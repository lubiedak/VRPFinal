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
import com.vrp.vrpBackend.service.JenkinsService;

@Controller
public class JenkinsController extends BaseController {

	private static final String URL = BASE_URL + "/jenkins";

	@Autowired
	private JenkinsService service;

	@RequestMapping(value = URL, method = RequestMethod.GET)
	public ResponseEntity<Object> endpoints() {
		GenericResponse response = new GenericResponse("");

		response.add(linkTo(methodOn(JenkinsController.class).endpoints()).withSelfRel());
		response.add(linkTo(methodOn(JenkinsController.class).actions()).withRel("triggerBuild"));
		response.add(linkTo(methodOn(JenkinsController.class).info()).withRel("getInfo"));
		
		return new ResponseEntity<Object>( response, HttpStatus.OK);
	}

	@RequestMapping(value = URL + "/build", method = RequestMethod.POST)
	public ResponseEntity<Object> actions() {
		return new ResponseEntity<Object>(service.triggerBuild(), HttpStatus.OK);
	}

	@RequestMapping(value = URL + "/info", method = RequestMethod.GET)
	public ResponseEntity<Object> info() {

		return new ResponseEntity<Object>(service, HttpStatus.OK);
	}
}
