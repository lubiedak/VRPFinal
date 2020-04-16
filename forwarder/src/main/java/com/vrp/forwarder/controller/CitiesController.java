package com.vrp.forwarder.controller;

import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.service.CitiesReader;
import com.vrp.forwarder.view.DrawableSolution;
import lombok.RequiredArgsConstructor;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@RestController
@RequiredArgsConstructor
public class CitiesController {


    private static final String URL = "api/v1/city";

    private final CitiesReader citiesReader;

    @RequestMapping(value = URL, method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public List<Node> allCities() {
        citiesReader.readCities();
        return citiesReader.getCities();
    }

    @RequestMapping(value = URL+"/divided/{n}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public DrawableSolution allCitiesDivided(@PathVariable int n) {
        citiesReader.readCities();
        return new DrawableSolution(new ArrayList<>(citiesReader.getCities()), n,null);
    }

    @RequestMapping(value = URL+"/region", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public Object CitiesDividedByRegion() {
        citiesReader.readCities();
        var map = citiesReader.getCities().stream().collect(Collectors.toMap(Node::getName, Node::getRegion));
        return map.keySet().stream().collect(Collectors.groupingBy(map::get));
    }

    @RequestMapping(value = URL+"/group", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public Object CitiesDividedByGroup() {
        citiesReader.readCities();
        var map = citiesReader.getCities().stream().collect(Collectors.toMap(Node::getName, Node::getRegion));
        return map.keySet().stream().collect(Collectors.groupingBy(map::get));
    }

}
