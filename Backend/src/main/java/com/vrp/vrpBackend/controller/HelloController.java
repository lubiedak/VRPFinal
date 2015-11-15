package com.vrp.vrpBackend.controller;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;


@Controller
public class HelloController extends BaseController {

	private static final String URL = BASE_URL + "/hello";
	
	@RequestMapping(value = URL, method = RequestMethod.GET)
	  public ResponseEntity<Object> actions() {
	    return new ResponseEntity<Object>(new String("worldbar"), HttpStatus.OK);
	  }
	
}
