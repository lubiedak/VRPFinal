package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Criteria;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

@Service
public class Divider {

    private final static int BASE_GROUP_SIZE = 18;

    public List<Problem> divideCitiesIntoProblems(List<Node> allCities) {
        List<Node> cities = new ArrayList<>(allCities);
        List<Node> depots = cities.stream()
                                  .filter(Node::isDepot)
                                  .collect(Collectors.toList());
        cities.removeAll(depots);
        Map<Node, List<Node>> map = depots.stream()
                                          .collect(Collectors.toMap(Function.identity(),
                                                                    depot -> cities.stream()
                                                                                   .filter(c -> c.getGroup()
                                                                                                 .equals(depot.getName()))
                                                                                   .collect(Collectors.toList())));
        return map.entrySet()
                  .stream()
                  .map(e -> Problem.builder()
                                   .depot(e.getKey())
                                   .nodes(e.getValue())
                                   .criteria(new Criteria())
                                   .build())
                  .collect(Collectors.toList());
    }

    public List<Problem> divide(Problem p){
        p.sortNodes();
        int totalSize = p.getNodes().size();
        int nOfGroups = (int)Math.ceil((totalSize+0.0)/BASE_GROUP_SIZE);
        float averageGroupSize = (totalSize+0.0f)/nOfGroups;
        List<Problem> problems = new ArrayList<>();
        int i;
        for(i = 0; i<nOfGroups-1; i++){
            System.out.println((int)(i*averageGroupSize));
            System.out.println((int)((i+1)*averageGroupSize));
            problems.add(Problem.builder().criteria(p.getCriteria()).depot(p.getDepot())
                                .nodes(p.getNodes().subList((int)(i*averageGroupSize), (int)((i+1)*averageGroupSize))).build());
        }

        System.out.println((int)(i*averageGroupSize));
        System.out.println(totalSize);
        problems.add(Problem.builder().criteria(p.getCriteria()).depot(p.getDepot())
                            .nodes(p.getNodes().subList((int)(i*averageGroupSize), totalSize)).build());

        return problems;
    }
}
