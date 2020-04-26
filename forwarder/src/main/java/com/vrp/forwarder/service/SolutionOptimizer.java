package com.vrp.forwarder.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.vrp.forwarder.model.Cycle;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import com.vrp.forwarder.model.Solution;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

@Service
@RequiredArgsConstructor
public class SolutionOptimizer {

    private static final int NODES_TO_OPTIMIZE = 16;
    private final VRPRunner vrpRunner;
    private final ObjectMapper objectMapper;

    public Solution improveMiddleCycles(Problem problem, Solution first, Solution second){
        first.countAngles(problem);
        second.countAngles(problem);
        Solution oldSolution = new Solution(Arrays.asList(first, second));
        double startingAngle = (first.getAngle() + second.getAngle())/2;
        int nodeCount = 0;
        int i=0;
        List<Cycle> allCycles = Stream.of(first.getCycles(), second.getCycles())
                                      .flatMap(Collection::stream)
                                      .sorted(Comparator.comparing(c -> Math.abs(c.getAngleToDepot() - startingAngle)))
                                      .collect(Collectors.toList());

        List<Cycle> cycles = new ArrayList<>();
        do{
            Cycle c = allCycles.get(i++);
            cycles.add(c);
            nodeCount+=c.getNodes().length-1;
        }while(nodeCount < NODES_TO_OPTIMIZE);

        allCycles.removeAll(cycles);
        Problem problemCopy = Problem.builder().build();
        try {
            problemCopy = objectMapper
                    .readValue(objectMapper.writeValueAsString(problem), Problem.class);
        }catch (JsonProcessingException ignored){}

        Solution improved = reRunForNewCycles(problem, cycles);
        Solution improved2 = reRunForNewCycles(problemCopy, allCycles);
        Solution old = rebuild(allCycles);
        System.out.println("Second half Before optimization: " + old.getDistance());

        System.out.println("After optimization: " + improved2.getDistance());

        Solution newSolution = new Solution(Arrays.asList(improved, old));

        System.out.println("Before optimization: " + oldSolution.getDistance());

        System.out.println("After optimization: " + newSolution.getDistance());
        return newSolution.getDistance() < oldSolution.getDistance() ? newSolution : oldSolution;
    }

    public Solution improveSolution(Problem problem, Solution solution){
        solution.countAngles(problem);
        List<Cycle> cycles = solution.getRandomSeries();
        return reRunForNewCycles(problem, cycles);
    }

    public Solution reRunForNewCycles(Problem problem, List<Cycle> cycles){
        int currentDistance = cycles.stream().mapToInt(Cycle::getDistance).sum();
        List<Node> nodes = cycles.stream()
                                 .map(c->c.toNodes(problem))
                                 .flatMap(List::stream)
                                 .filter(n->!n.getName().equals("Depot"))
                                 .distinct()
                                 .collect(Collectors.toList());
        problem.setNodes(nodes);
        Solution improvedSolution = vrpRunner.run(problem);
        if(currentDistance > improvedSolution.getDistance()){
            return improvedSolution;
        }

        return improvedSolution;
    }

    private Solution rebuild(List<Cycle> cycles){
        int demand = cycles.stream().mapToInt(Cycle::getDemand).sum();
        int distance = cycles.stream().mapToInt(Cycle::getDistance).sum();
        return Solution.builder().cycles(cycles).demand(demand).distance(distance).build();
    }
}
