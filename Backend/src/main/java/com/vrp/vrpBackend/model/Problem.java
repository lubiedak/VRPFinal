package com.vrp.vrpBackend.model;

import java.util.List;

import com.vrp.vrpBackend.divider.NodeClassifier;

import lombok.Data;

@Data
public class Problem {
	List<Node> nodes;
	Criteria criteria;

	@Override
	public String toString() {
		String str = "";
		str += criteria.toString() + "\n";
		for (Node n : nodes) {
			str += n.toString() + "\n";
		}
		return str;
	}
	
	public void sortNodes(){
		Node base = nodes.stream()
				.filter(x -> x.getName().equals("Depot"))
				.findFirst()
				.get();
		NodeClassifier classifier = new NodeClassifier(base);
		
		nodes.forEach((node) -> node.setAngle(classifier.classify(node)));
	}

}
