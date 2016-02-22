package com.vrp.vrpBackend.service.impl;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import org.springframework.stereotype.Component;

import com.vrp.vrpBackend.model.GeneratorCfg;
import com.vrp.vrpBackend.model.Node;
import com.vrp.vrpBackend.service.NodesGenerator;

/**
 * @author lubiedak
 *
 */
@Component
public class NodesGeneratorImpl implements NodesGenerator {

	private GeneratorCfg cfg;
	private Random rnd;

	@Override
	public List<Node> generateNodes(GeneratorCfg cfg) {
		this.cfg = cfg;
		this.rnd = new Random();

		List<Node> nodes = new ArrayList<Node>();
		nodes.add(createNode(0, "Depot"));
		for (int i = 1; i < cfg.getNodesCount(); ++i) {
			nodes.add(createNode(i, "" + i));
		}

		return nodes;
	}

	private Node createNode(int id, String name) {
		Node node = new Node(name);

		node.setId(id);
		node.setX(rnd.nextInt(cfg.getMaxX()));
		node.setY(rnd.nextInt(cfg.getMaxY()));
		node.setDemand(cfg.getMinDemand() + rnd.nextInt(cfg.getMaxDemand() - cfg.getMinDemand()));

		return node;
	}

}
