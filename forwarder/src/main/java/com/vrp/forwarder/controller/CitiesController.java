package com.vrp.forwarder.controller;

import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.service.CitiesReader;
import lombok.RequiredArgsConstructor;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

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

}
