package com.vrp.vrpBackend.controller;

import static org.springframework.hateoas.mvc.ControllerLinkBuilder.linkTo;
import static org.springframework.hateoas.mvc.ControllerLinkBuilder.methodOn;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import com.vrp.vrpBackend.controller.dto.GenericResponse;
import com.vrp.vrpBackend.controller.dto.Nodes;
import com.vrp.vrpBackend.model.Criteria;
import com.vrp.vrpBackend.model.GeneratorCfg;
import com.vrp.vrpBackend.model.Node;
import com.vrp.vrpBackend.model.Problem;
import com.vrp.vrpBackend.service.NodesGenerator;
import com.vrp.vrpBackend.service.VRPRunner;

@Controller
public class NodeController extends BaseController {

	private static final String URL = BASE_URL + "/node";


	@Autowired
	private NodesGenerator generator;
	
	@Autowired
	private VRPRunner vrpRunner;
	
	
	@RequestMapping(value = URL, method = RequestMethod.GET)
	public ResponseEntity<Object> endpoints() {
		GenericResponse response = new GenericResponse("");

		response.add(linkTo(methodOn(NodeController.class).endpoints()).withSelfRel());
		response.add(linkTo(methodOn(NodeController.class).generate(0, 0, 0, 0, 0, "text", "text", false)).withRel("generate"));

		
		return new ResponseEntity<Object>( response, HttpStatus.OK);
	}


	@RequestMapping(value = URL + "/generate", method = RequestMethod.POST)
	public ResponseEntity<Object> generate( @RequestParam int nodesCount,
											@RequestParam int minDemand,
											@RequestParam int maxDemand, 
											@RequestParam int maxX,
											@RequestParam int maxY,
											@RequestParam(required=false) String distribution,
											@RequestParam(required=false, defaultValue="xx") String name,
											@RequestParam(required=false, defaultValue="false") boolean dbSave) {

		GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand,
											maxX, maxY, distribution, name, dbSave);

		List<Node> n = generator.generateNodes(cfg);
		Nodes nodes = new Nodes(name);
		nodes.setNodes(n);


		return new ResponseEntity<Object>(nodes, HttpStatus.OK);
	}
	
	@RequestMapping(value = URL + "/generateAndSolve", method = RequestMethod.POST)
	public ResponseEntity<Object> generateAndSolve( @RequestParam int nodesCount,
											@RequestParam int minDemand,
											@RequestParam int maxDemand, 
											@RequestParam int maxX,
											@RequestParam int maxY,
											@RequestParam(required=false) String distribution,
											@RequestParam(required=false, defaultValue="xx") String name,
											@RequestParam(required=false, defaultValue="false") boolean dbSave) {

		GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand,
											maxX, maxY, distribution, name, dbSave);

		List<Node> nodes = generator.generateNodes(cfg);
		Problem p = new Problem();
		p.setCriteria(new Criteria());
		p.setNodes(nodes);


		return new ResponseEntity<Object>(vrpRunner.run(p), HttpStatus.OK);
	}	
}