package com.vrp.forwarder.model;

import com.vrp.forwarder.divider.NodeClassifier;
import lombok.Builder;
import lombok.Data;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

@Data
@Builder
public class Problem {
	List<Node> nodes;
	Criteria criteria;
	Node depot;

	public void sortNodes(){
		NodeClassifier classifier = new NodeClassifier(depot);
		
		nodes.forEach((node) -> node.setAngle(classifier.classify(node)));
		nodes.sort(Comparator.comparing(Node::getAngle));
	}

	List<Node> getNodesWithDepot(){
		return Stream.concat(Stream.of(depot), nodes.stream())
					 .collect(Collectors.toList());
	}

}
