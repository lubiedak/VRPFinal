package com.vrp.forwarder.controller;

import com.vrp.forwarder.model.*;
import com.vrp.forwarder.service.*;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequiredArgsConstructor
public class ProblemController {

    private static final String URL = "api/v1/problem";

    private final ProblemGenerator problemGenerator;

    private final VRPManager vrpManager;


    @RequestMapping(value = URL, method = RequestMethod.GET)
    public ResponseEntity<Object> endpoints() {
        return new ResponseEntity<>(generate(0, 0, 0, 0, 0), HttpStatus.OK);
    }


    @RequestMapping(value = URL + "/generate", method = RequestMethod.POST)
    public ResponseEntity<Object> generate( @RequestParam int nodesCount,
                                            @RequestParam int minDemand,
                                            @RequestParam int maxDemand,
                                            @RequestParam int maxX,
                                            @RequestParam int maxY) {

        GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand, maxX, maxY);

        Problem problem = problemGenerator.generate(cfg);
        problem.sortNodes();

        return new ResponseEntity<>(problem, HttpStatus.OK);
    }

    @RequestMapping(value = URL + "/generateAndSolve", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity generateAndSolve(@RequestParam int nodesCount,
                                           @RequestParam int minDemand,
                                           @RequestParam int maxDemand,
                                           @RequestParam int maxX,
                                           @RequestParam int maxY,
                                           @RequestParam(required=false) boolean draw) {

        GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand, maxX, maxY);

        return vrpManager.runAndReturnSolution(draw, problemGenerator.generate(cfg));
    }

}
