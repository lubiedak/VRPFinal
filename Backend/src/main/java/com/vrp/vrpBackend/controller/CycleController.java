package com.vrp.vrpBackend.controller;

import static org.springframework.hateoas.mvc.ControllerLinkBuilder.linkTo;
import static org.springframework.hateoas.mvc.ControllerLinkBuilder.methodOn;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.vrp.vrpBackend.controller.dto.GenericResponse;
import com.vrp.vrpBackend.service.CycleService;

@Controller
public class CycleController extends BaseController {

	private static final String URL = BASE_URL + "/cycle";

	@Autowired
	private CycleService cycleService;

	
	@RequestMapping(value = URL, method = RequestMethod.GET)
	public ResponseEntity<Object> endpoints() {
		GenericResponse response = new GenericResponse("");

		response.add(linkTo(methodOn(CycleController.class).endpoints()).withSelfRel());
		response.add(linkTo(methodOn(CycleController.class).solve()).withRel("solve"));
		
		return new ResponseEntity<Object>( response, HttpStatus.OK);
	}


	@RequestMapping(value = URL + "/solveRandom", method = RequestMethod.POST)
	public ResponseEntity<Object> solve( ) {
		
		cycleService.generateRandom(5, 10);
		
		
		return new ResponseEntity<Object>(cycleService.generateRandom(5, 10), HttpStatus.OK);
	}
}