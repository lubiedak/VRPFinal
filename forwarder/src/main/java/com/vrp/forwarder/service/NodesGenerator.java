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
        nodes.add(Node.builder()
                      .name("Depot")
                      .x(cfg.getMaxX()/2)
                      .y(cfg.getMaxY()/2)
                      .build());

        for (int i = 1; i < cfg.getNodesCount()+1; ++i) {
            nodes.add(createNode(i, "" + i));
        }

        return nodes;
    }

    private Node createNode(int id, String name) {
        return Node.builder()
                   .name(name)
                   .id(id)
                   .x(rnd.nextInt(cfg.getMaxX()))
                   .y(rnd.nextInt(cfg.getMaxY()))
                   .demand(cfg.getMinDemand() + rnd.nextInt(cfg.getMaxDemand() - cfg.getMinDemand()))
                .build();
    }
}
