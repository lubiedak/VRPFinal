package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Cycle;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import com.vrp.forwarder.model.Solution;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class SolutionOptimizer {


    private final VRPRunner vrpRunner;

    public Solution improveSolution(Problem problem, Solution solution){
        solution.sortCycles(problem);
        List<Cycle> cycles = solution.getRandomSeries();
        int currentDistance = cycles.stream().mapToInt(Cycle::getDistance).sum();
        List<Node> nodes = cycles.stream()
                                 .map(c->c.toNodes(problem))
                                 .flatMap(List::stream)
                                 .distinct()
                                 .collect(Collectors.toList());
        problem.setNodes(nodes);
        Solution improvedSolution = vrpRunner.run(problem);
        if(currentDistance > improvedSolution.getDistance()){
            return improvedSolution;
        }

        return solution;
    }
}
