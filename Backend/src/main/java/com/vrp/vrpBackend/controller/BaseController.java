package com.vrp.vrpBackend.controller;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

public abstract class BaseController {

  protected HttpStatus status = HttpStatus.OK;

  protected static final ResponseEntity<Object> everythingIsFine =
      new ResponseEntity<>(null, HttpStatus.OK);

  protected static final String BASE_URL = "/rest";

}