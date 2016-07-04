package com.vrp.vrpBackend.divider;

import com.vrp.vrpBackend.model.Node;

public class NodeClassifier {
	Node baseNode;
	
	public NodeClassifier(Node baseNode) {
		this.baseNode = baseNode;
	}

	public double classify(Node n){
		double x = n.getX() - baseNode.getX();
		double y = n.getY() - baseNode.getY()+0.000000001;
		
		double atan = Math.atan(x/y);
		if(x < 0)
			atan += Math.PI;
		if(x > 0 && y < 0)
			atan += 2*Math.PI;
		return atan*180/Math.PI;
	}
}
