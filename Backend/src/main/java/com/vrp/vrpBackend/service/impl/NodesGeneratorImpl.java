package com.vrp.vrpBackend.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Component;

import com.vrp.vrpBackend.model.GeneratorParams;
import com.vrp.vrpBackend.model.Node;
import com.vrp.vrpBackend.service.NodesGenerator;

/**
 * @author lubiedak
 *
 */
@Component
public class NodesGeneratorImpl implements NodesGenerator {

	@Override
	public List<Node> generateNodes(GeneratorParams params) {

		List<Node> nodes = new ArrayList<Node>();
		nodes.add(new Node("a"));
		nodes.add(new Node("b"));
		
		return nodes;
	}

}
