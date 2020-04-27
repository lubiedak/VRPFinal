package com.vrp.forwarder.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.vrp.forwarder.divider.Divider;
import com.vrp.forwarder.model.Problem;
import com.vrp.forwarder.model.Solution;
import com.vrp.forwarder.view.DrawableSolution;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class VRPManager {

    private final VRPRunner vrpRunner;

    private final Divider divider;

    private final SolutionOptimizer solutionOptimizer;

    private final ObjectMapper objectMapper;

    public ResponseEntity runAndReturnSolution(boolean draw, Problem problem) {
        Problem problemCopy = makeCopy(problem);

        List<Problem> problems = divider.divide(problem,18);
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

    private Problem makeCopy(Problem problem){
        Problem problemCopy = Problem.builder().build();
        try {
            problemCopy = objectMapper
                    .readValue(objectMapper.writeValueAsString(problem), Problem.class);
        }catch (JsonProcessingException ignored){}
        return problemCopy;
    }
}
