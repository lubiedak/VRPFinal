package com.vrp.forwarder.controller;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.vrp.forwarder.model.*;
import com.vrp.forwarder.service.*;
import com.vrp.forwarder.view.DrawableSolution;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequiredArgsConstructor
public class ProblemController {

    private static final String URL = "api/v1/problem";

    private final ProblemGenerator problemGenerator;

    private final VRPRunner vrpRunner;

    private final Divider divider;

    private final SolutionOptimizer solutionOptimizer;

    private final ObjectMapper objectMapper;


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
    public ResponseEntity<Object> generateAndSolve( @RequestParam int nodesCount,
                                                    @RequestParam int minDemand,
                                                    @RequestParam int maxDemand,
                                                    @RequestParam int maxX,
                                                    @RequestParam int maxY,
                                                    @RequestParam(required=false) boolean draw) {

        GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand, maxX, maxY);

        return runAndReturnSolution(draw, problemGenerator.generate(cfg));
    }

    @RequestMapping(value = URL + "/generateAndSolve4Cities", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity<Object> generateAndSolve4Cities( @RequestParam int nodesCount,
                                                    @RequestParam int minDemand,
                                                    @RequestParam int maxDemand,
                                                    @RequestParam int maxX,
                                                    @RequestParam int maxY,
                                                    @RequestParam(required=false) boolean draw) {

        GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand, maxX, maxY);
        return runAndReturnSolution(draw, problemGenerator.generateForCities(cfg));
    }

    private ResponseEntity runAndReturnSolution(boolean draw, Problem problem) {
        Problem problemCopy = Problem.builder().build();
        try {
            problemCopy = objectMapper
                    .readValue(objectMapper.writeValueAsString(problem), Problem.class);
        }catch (JsonProcessingException ignored){}

        List<Problem> problems = divider.divide(problem);
        List<Solution> solutions = problems.stream()
                                           .map(vrpRunner::run)
                                           .collect(Collectors.toList());
        Solution allSolutions = new Solution(solutions);

        Solution optimized = solutionOptimizer.improveMiddleCycles(problem, solutions.get(0), solutions.get(1));
        if (draw) {
            DrawableSolution drawableSolution = new DrawableSolution(problemCopy, optimized);

            DrawableSolution drawableSolution2 = new DrawableSolution(problemCopy, allSolutions);

            return ResponseEntity.ok(Arrays.asList(drawableSolution, drawableSolution2));
        }

        return new ResponseEntity<>(optimized, HttpStatus.OK);
    }

}
