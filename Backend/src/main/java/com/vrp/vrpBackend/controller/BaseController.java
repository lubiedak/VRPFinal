package com.vrp.vrpBackend.controller;

import static org.springframework.hateoas.mvc.ControllerLinkBuilder.linkTo;
import static org.springframework.hateoas.mvc.ControllerLinkBuilder.methodOn;

import org.springframework.hateoas.ResourceSupport;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

import com.vrp.vrpBackend.controller.dto.GenericResponse;

public abstract class BaseController extends ResourceSupport {

	protected HttpStatus status = HttpStatus.OK;

	protected static final ResponseEntity<Object> everythingIsFine = new ResponseEntity<>(null, HttpStatus.OK);

	protected static final String BASE_URL = "/rest";

	protected GenericResponse createGenericResponse(Class controller) {
		String name = "";
		GenericResponse response = new GenericResponse(name);
		
		response.add(linkTo(methodOn(controller)).withSelfRel());
		return response;
	}

}