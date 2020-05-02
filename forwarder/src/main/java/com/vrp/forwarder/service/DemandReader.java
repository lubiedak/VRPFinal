package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Criteria;
import com.vrp.forwarder.model.GeneratorCfg;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Random;

@Service
@RequiredArgsConstructor
public class DemandReader {
    private final CitiesReader citiesReader;

    private final Random rnd = new Random();

    public Problem generateForCities(GeneratorCfg cfg) {
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

    private int rndDemand(GeneratorCfg cfg){
        return cfg.getMinDemand() + rnd.nextInt(cfg.getMaxDemand() - cfg.getMinDemand());
    }
}
