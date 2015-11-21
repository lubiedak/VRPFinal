package com.vrp.vrpBackend.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.vrp.vrpBackend.service.JenkinsService;

@Controller
public class JenkinsController extends BaseController {

	private static final String URL = BASE_URL + "/jenkins";

	@Autowired
	private JenkinsService service;
	
	@RequestMapping(value = URL, method = RequestMethod.GET)
	public ResponseEntity<Object> endpoints() {
		
		return new ResponseEntity<Object>(new String("/build\n/info"), HttpStatus.OK);
	}
	

	@RequestMapping(value = URL+"/build", method = RequestMethod.POST)
	public ResponseEntity<Object> actions() {
		
		return new ResponseEntity<Object>(service.triggerBuild(), HttpStatus.OK);
	}
	
	@RequestMapping(value = URL+"/info", method = RequestMethod.GET)
	public ResponseEntity<Object> getJenkinsURL() {
		
		
		return new ResponseEntity<Object>(service.getJenkinsInfo(), HttpStatus.OK);
	}

}
