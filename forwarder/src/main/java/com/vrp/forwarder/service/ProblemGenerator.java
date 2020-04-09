package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Criteria;
import com.vrp.forwarder.model.GeneratorCfg;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;


@Service
@RequiredArgsConstructor
public class ProblemGenerator {

    private final CitiesReader citiesReader;

    private final Random rnd = new Random();

    public Problem generate(GeneratorCfg cfg) {
        List<Node> nodes = new ArrayList<Node>();
        Node depot = Node.builder()
                         .name("Depot")
                         .x(cfg.getMaxX() / 2)
                         .y(cfg.getMaxY() / 2)
                         .build();

        for (int i = 1; i < cfg.getNodesCount() + 1; ++i) {
            nodes.add(createNode(cfg, i, "" + i));
        }
        return Problem.builder()
                      .nodes(nodes)
                      .depot(depot)
                      .criteria(new Criteria())
                      .build();
    }

    public Problem generateForCities(GeneratorCfg cfg) {
        citiesReader.readCities();
        List<Node> cities = citiesReader.getCities();
        Node depot = cities.stream().filter(c-> c.getName().equals("Łódź")).findFirst().orElseGet(null);
        cities.remove(depot);
        cities.forEach(c -> c.setDemand(rndDemand(cfg)));


        return Problem.builder()
                      .nodes(cities.subList(0,200))
                      .depot(depot)
                      .criteria(new Criteria())
                      .build();
    }

    private Node createNode(GeneratorCfg cfg, int id, String name) {
        return Node.builder()
                   .name(name)
                   .id(id)
                   .distance_id(id)
                   .x(rnd.nextInt(cfg.getMaxX()))
                   .y(rnd.nextInt(cfg.getMaxY()))
                   .demand(rndDemand(cfg))
                   .build();
    }

    private int rndDemand(GeneratorCfg cfg){
        return cfg.getMinDemand() + rnd.nextInt(cfg.getMaxDemand() - cfg.getMinDemand());
    }
}
