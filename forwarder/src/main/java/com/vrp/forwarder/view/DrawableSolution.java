package com.vrp.forwarder.view;

import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import com.vrp.forwarder.model.Solution;
import lombok.Data;
import lombok.extern.slf4j.Slf4j;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

@Data
public class DrawableSolution {
    List<NodeD> nodes;
    List<Edge> edges;

    public DrawableSolution(Problem problem, Solution solution) {
        nodes = problem.getNodes().stream().map(NodeD::new).collect(Collectors.toList());
        nodes.add(new NodeD(problem.getDepot().toBuilder().demand(solution.getDistance()).build()));
        edges = solution.getCycles().stream().map(Edge::edges).flatMap(List::stream).collect(Collectors.toList());
    }

    public DrawableSolution(List<Problem> problems, List<Solution> solutions){
        nodes = problems.stream()
        .map(p-> p.getNodes().stream().map(NodeD::new).collect(Collectors.toList()))
        .flatMap(List::stream).collect(Collectors.toList());

        List <NodeD> depots = problems.stream().map(p-> new NodeD(p.getDepot().toBuilder().demand(solutions.get(0).getDistance()).build())).collect(Collectors.toList());
        nodes.addAll(depots);
        edges = solutions.stream()
                        .map(s -> s.getCycles().stream()
                            .map(Edge::edges).flatMap(List::stream)
                            .collect(Collectors.toList()))
                        .flatMap(List::stream).collect(Collectors.toList());
    }

    public DrawableSolution(List<Node> cities, int n, List<String> depots) {
        int minX = cities.stream().min(Comparator.comparing(Node::getX)).orElseThrow().getX();
        int maxX = cities.stream().max(Comparator.comparing(Node::getX)).orElseThrow().getX();
        int minY = cities.stream().min(Comparator.comparing(Node::getY)).orElseThrow().getY();
        int maxY = cities.stream().max(Comparator.comparing(Node::getY)).orElseThrow().getY();

        edges = new ArrayList<>();
        List<Node> markers = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            int x = minX + i * (maxX - minX) / n;
            int y = minY + i * (maxY - minY) / n;
            markers.add(Node.builder().x(minX).y(y).demand(100).id(1000 + i).name("x" + i).build());
            markers.add(Node.builder().x(maxX).y(y).demand(100).id(2000 + i).name("x" + i).build());
            edges.add(Edge.builder().source(1000 + i).target(2000 + i).id("" + 12 + i).build());

            markers.add(Node.builder().x(x).y(minY).demand(100).id(3000 + i).name("y" + i).build());
            markers.add(Node.builder().x(x).y(maxY).demand(100).id(4000 + i).name("y" + i).build());

            edges.add(Edge.builder().source(3000 + i).target(4000 + i).id("" + 34 + i).build());
        }
        cities.addAll(markers);
        nodes = cities.stream().map(NodeD::new).collect(Collectors.toList());
    }
}
