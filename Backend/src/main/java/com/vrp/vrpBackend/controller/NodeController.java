package com.vrp.vrpBackend.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.vrp.vrpBackend.model.Node;
import com.vrp.vrpBackend.service.NodeService;

@Controller
public class NodeController extends BaseController {

	private static final String URL = BASE_URL + "/node";

	@Autowired
	private NodeService service;

	@RequestMapping(value = URL + "/build", method = RequestMethod.POST)
	public ResponseEntity<Object> actions() {
		
		Node node = new Node();
		node.setDemand(100);
		node.setName("Dupa");
		node.setX(50);
		
		
		return new ResponseEntity<Object>(service.save(node), HttpStatus.OK);
	}
}