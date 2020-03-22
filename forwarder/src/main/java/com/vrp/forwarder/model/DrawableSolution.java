package com.vrp.forwarder.model;

import lombok.Data;

import java.util.ArrayList;
import java.util.List;

@Data
public class DrawableSolution {
    List<Node> nodes;
    List<Edge> edges;

    public DrawableSolution(Problem problem, List<Solution> solutions){
        nodes = problem.getNodes();
        nodes.add(problem.getDepot());
        edges = new ArrayList<>();
    }
}
