package com.vrp.forwarder.controller;

import com.vrp.forwarder.model.*;
import com.vrp.forwarder.service.Divider;
import com.vrp.forwarder.service.NodesGenerator;
import com.vrp.forwarder.service.VRPRunner;
import com.vrp.forwarder.view.DrawableSolution;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequiredArgsConstructor
public class ProblemController {

    private static final String URL = "api/v1/problem";

    private final NodesGenerator generator;

    private final VRPRunner vrpRunner;

    private final Divider divider;


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

        List<Node> nodes = generator.generateNodes(cfg);

        Problem problem = Problem.builder().criteria(new Criteria()).nodes(nodes).build();
        problem.sortNodes();

        return new ResponseEntity<>(problem, HttpStatus.OK);
    }

    @RequestMapping(value = URL + "/generateAndSolve", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity<Object> generateAndSolve( @RequestParam int nodesCount,
                                                    @RequestParam int minDemand,
                                                    @RequestParam int maxDemand,
                                                    @RequestParam int maxX,
                                                    @RequestParam int maxY,
                                                    @RequestParam(required=false) boolean draw) {

        GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand, maxX, maxY);

        List<Node> nodes = generator.generateNodes(cfg);
        Problem problem = Problem.builder().criteria(new Criteria()).nodes(nodes).build();
        List<Problem> problems = divider.divide(problem);
        List<Solution> solutions = problems.stream()
                                           .map(vrpRunner::run)
                                           .collect(Collectors.toList());
        Solution allSolutions = new Solution(solutions);
        if(draw){
            DrawableSolution drawableSolution = new DrawableSolution(problem, allSolutions);
            return new ResponseEntity<>(drawableSolution, HttpStatus.OK);
        }

        return new ResponseEntity<>(allSolutions, HttpStatus.OK);
    }
}
