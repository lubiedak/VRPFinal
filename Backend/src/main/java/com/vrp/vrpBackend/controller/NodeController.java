package com.vrp.vrpBackend.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import com.vrp.vrpBackend.controller.dto.NodesDto;
import com.vrp.vrpBackend.model.GeneratorParams;
import com.vrp.vrpBackend.model.Node;
import com.vrp.vrpBackend.service.NodeService;
import com.vrp.vrpBackend.service.NodesGenerator;

@Controller
public class NodeController extends BaseController {

	private static final String URL = BASE_URL + "/node";

	@Autowired
	private NodeService nodeService;

	@Autowired
	private NodesGenerator generator;

	@RequestMapping(value = URL + "/build", method = RequestMethod.POST)
	public ResponseEntity<Object> actions() {

		Node node = new Node("Dupa");
		node.setDemand(100);
		node.setX(50);

		return new ResponseEntity<Object>(nodeService.save(node), HttpStatus.OK);
	}

	@RequestMapping(value = URL + "/generate", method = RequestMethod.POST)
	public ResponseEntity<Object> generate( @RequestParam int nodesCount, @RequestParam int minDemand,
											@RequestParam int maxDemand,  @RequestParam int maxX,
											@RequestParam int maxY,	      @RequestParam String distribution,
											@RequestParam String name,    @RequestParam boolean dbSave) {

		GeneratorParams params = new GeneratorParams(nodesCount, minDemand, maxDemand, maxX, maxY, distribution, name, dbSave);

		List<Node> n = generator.generateNodes(params);
		NodesDto nodes = new NodesDto();
		nodes.setNodes(n);

		return new ResponseEntity<Object>(nodes, HttpStatus.OK);
	}
}