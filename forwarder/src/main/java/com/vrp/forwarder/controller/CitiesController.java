package com.vrp.forwarder.controller;

import com.vrp.forwarder.model.GeneratorCfg;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.service.CitiesReader;
import com.vrp.forwarder.service.VRPManager;
import com.vrp.forwarder.view.DrawableSolution;
import lombok.RequiredArgsConstructor;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequiredArgsConstructor
public class CitiesController {


    private static final String URL = "api/v1/city";

    private final CitiesReader citiesReader;
    private final VRPManager vrpManager;

    @RequestMapping(value = URL, method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public List<Node> allCities() {
        return citiesReader.getCities();
    }

    @RequestMapping(value = URL+"/divided/{n}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public DrawableSolution allCitiesDivided(@PathVariable int n) {
        return new DrawableSolution(new ArrayList<>(citiesReader.getCities()), n,null);
    }

    @RequestMapping(value = URL+"/region", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public Object citiesDividedByRegion() {
        var map = citiesReader.getCities().stream().collect(Collectors.toMap(Node::getName, Node::getRegion));
        return map.keySet().stream().collect(Collectors.groupingBy(map::get));
    }

    @RequestMapping(value = URL+"/group", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public Object CitiesDividedByGroup() {
        var map = citiesReader.getCities().stream().collect(Collectors.toMap(Node::getName, Node::getGroup));
        return map.keySet().stream().collect(Collectors.groupingBy(map::get));
    }


    @RequestMapping(value = URL+"/group/{name}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
    public Object citiesFromGroup(@PathVariable String name) {
        List<Node> citiesFromGroup = citiesReader.getCities()
                                                 .stream()
                                                 .filter(c->c.getGroup().equals(name))
                                                 .collect(Collectors.toList());
        return new DrawableSolution(citiesFromGroup, 1,null);
    }

    @RequestMapping(value = URL + "/demand/{name}", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity generateAndSolve(@PathVariable String name) {

        return null;
    }

}
