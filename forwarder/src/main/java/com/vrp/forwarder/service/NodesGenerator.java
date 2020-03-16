package com.vrp.forwarder.service;

import com.vrp.forwarder.model.GeneratorCfg;
import com.vrp.forwarder.model.Node;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;


@Service
public class NodesGenerator {
    private GeneratorCfg cfg;
    private Random rnd;

    public List<Node> generateNodes(GeneratorCfg cfg) {
        this.cfg = cfg;
        this.rnd = new Random();

        List<Node> nodes = new ArrayList<Node>();
        nodes.add(createNode(0, "Depot"));
        for (int i = 1; i < cfg.getNodesCount()+1; ++i) {
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
