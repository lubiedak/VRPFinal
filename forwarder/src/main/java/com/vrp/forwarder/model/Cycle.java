package com.vrp.forwarder.model;

import lombok.Data;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Data
public class Cycle {

	private int[] nodes;
	private int distance;
	private int demand;
	private int capacity;
	private double angleToDepot;

	public void countAngleToDepot(Problem problem){
		List<Node> nodes = toNodes(problem);
		double nodesX = nodes.stream().mapToDouble(Node::getX).sum()/nodes.size();
		double nodesY = nodes.stream().mapToDouble(Node::getY).sum()/nodes.size();

		double x = nodesX - problem.getDepot().getX();
		double y = nodesY - problem.getDepot().getY();
		double atan = Math.atan(x/y);
		if(x < 0)
			atan += Math.PI;
		if(x > 0 && y < 0)
			atan += 2* Math.PI;
		angleToDepot = atan*180 / Math.PI;
	}

	public List<Node> toNodes(Problem problem){
		return problem.getNodesWithDepot()
					  .stream()
					  .filter(node-> Arrays.stream(nodes).anyMatch(id -> node.getId()==id))
					  .collect(Collectors.toList());
	}
}
