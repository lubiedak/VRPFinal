package com.vrp.vrpBackend.controller;

import org.springframework.hateoas.ResourceSupport;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

public abstract class BaseController extends ResourceSupport {

	protected HttpStatus status = HttpStatus.OK;

	protected static final ResponseEntity<Object> everythingIsFine = new ResponseEntity<>(null, HttpStatus.OK);

	protected static final String BASE_URL = "/rest";
}