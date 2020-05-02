package com.vrp.forwarder.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.vrp.forwarder.divider.Divider;
import com.vrp.forwarder.model.GeneratorCfg;
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
    private final CitiesReader citiesReader;
    private final SolutionOptimizer solutionOptimizer;
    private final ObjectMapper objectMapper;

    public ResponseEntity runForCities(final boolean draw) {
        
        List<Problem> problemsPerDepot = divider.divideCitiesIntoProblems(citiesReader.getCities());
        
        List<Problem> problems = problemsPerDepot.stream().map(p-> divider.divide(p, 16)).flatMap(List::stream).collect(Collectors.toList());

        final List<Solution> solutions = problems.stream().map(vrpRunner::runForCities).collect(Collectors.toList());
        if (draw) {
            final DrawableSolution drawableSolution = new DrawableSolution(problemsPerDepot, solutions);
            return ResponseEntity.ok(drawableSolution);
        }
        return new ResponseEntity<>(solutions, HttpStatus.OK);
    }

    public ResponseEntity runAndReturnSolution(final boolean draw, final Problem problem) {
        final Problem problemCopy = makeCopy(problem);

        final List<Problem> problems = divider.divide(problem, 18);
        final List<Solution> solutions = problems.stream().map(vrpRunner::runStandard).collect(Collectors.toList());
        final Solution allSolutions = new Solution(solutions);

        final Solution optimized = solutionOptimizer.improveMiddleCycles(problem, solutions.get(0), solutions.get(1));
        if (draw) {
            final DrawableSolution drawableSolution = new DrawableSolution(problemCopy, optimized);

            final DrawableSolution drawableSolution2 = new DrawableSolution(problemCopy, allSolutions);

            return ResponseEntity.ok(Arrays.asList(drawableSolution, drawableSolution2));
        }

        return new ResponseEntity<>(optimized, HttpStatus.OK);
    }


    private Problem makeCopy(final Problem problem) {
        Problem problemCopy = null;
        try {
            problemCopy = objectMapper.readValue(objectMapper.writeValueAsString(problem), Problem.class);
        } catch (final JsonProcessingException ignored) {
        }
        return problemCopy;
    }
}
