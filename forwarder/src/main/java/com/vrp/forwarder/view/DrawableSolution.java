package com.vrp.forwarder.view;

import com.vrp.forwarder.model.Problem;
import com.vrp.forwarder.model.Solution;
import lombok.Data;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Data
public class DrawableSolution {
    List<NodeD> nodes;
    List<Edge> edges;

    public DrawableSolution(Problem problem, List<Solution> solutions){
        nodes = problem.getNodes().stream().map(NodeD::new).collect(Collectors.toList());
        nodes.add(new NodeD(problem.getDepot().toBuilder().demand(1000).build()));
        edges = new ArrayList<>();
    }


}
