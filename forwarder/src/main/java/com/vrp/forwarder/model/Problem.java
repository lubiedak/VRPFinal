package com.vrp.forwarder.model;

import com.vrp.forwarder.divider.NodeClassifier;
import lombok.Builder;
import lombok.Data;

import java.util.Comparator;
import java.util.List;

@Data
@Builder
public class Problem {
	List<Node> nodes;
	Criteria criteria;
	Node depot;


	public void sortNodes(){
		depot = nodes.stream()
				.filter(x -> x.getName().equals("Depot"))
				.findFirst()
				.get();
		nodes.remove(depot);
		NodeClassifier classifier = new NodeClassifier(depot);
		
		nodes.forEach((node) -> node.setAngle(classifier.classify(node)));
		nodes.sort(Comparator.comparing(Node::getAngle));
	}

}
