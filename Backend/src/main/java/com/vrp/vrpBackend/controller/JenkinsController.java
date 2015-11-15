package com.vrp.vrpBackend.controller;

import org.springframework.beans.factory.annotation.Autowired;
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
	  public void actions() {
	    service.triggerBuild();
	  }
	
}
