package com.vrp.forwarder.model;

import com.vrp.forwarder.divider.NodeClassifier;
import lombok.Builder;
import lombok.Data;

import java.util.ArrayList;
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
		double maxDifference = 0.0;
		int node = 0;
		for(int i=0; i<nodes.size()-1;i++){
			double diff = nodes.get(i+1).getAngle() - nodes.get(i).getAngle();
			if(diff>maxDifference){
				maxDifference = diff;
				node = i;
			}
		}
		List<Node> nodesCopy = new ArrayList<>(nodes);
		nodes = nodesCopy.subList(node+1, nodesCopy.size());
		nodes.addAll(nodesCopy.subList(0,node+1));
	}

	List<Node> getNodesWithDepot(){
		return Stream.concat(Stream.of(depot), nodes.stream())
					 .collect(Collectors.toList());
	}

}
