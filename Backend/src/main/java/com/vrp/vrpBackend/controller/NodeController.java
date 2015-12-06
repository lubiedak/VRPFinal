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
import com.vrp.vrpBackend.model.GeneratorCfg;
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
	
	
	@RequestMapping(value = URL, method = RequestMethod.GET)
	public ResponseEntity<Object> endpoints() {
		GenericResponse response = new GenericResponse("");

		response.add(linkTo(methodOn(NodeController.class).endpoints()).withSelfRel());
		response.add(linkTo(methodOn(NodeController.class).generate(0, 0, 0, 0, 0, "dist", "", false)).withRel("generate"));
		
		return new ResponseEntity<Object>( response, HttpStatus.OK);
	}

	@RequestMapping(value = URL + "/generate", method = RequestMethod.POST)
	public ResponseEntity<Object> generate( @RequestParam(value = "nodesCount", required = false, defaultValue = "50") int nodesCount,
											@RequestParam(value = "minDemand",  required = false, defaultValue = "100") int minDemand,
											@RequestParam(value = "maxDemand",  required = false, defaultValue = "1000") int maxDemand,
											@RequestParam(value = "maxX",       required = false, defaultValue = "800") int maxX,
											@RequestParam(value = "maxY",       required = false, defaultValue = "600") int maxY,
											@RequestParam(value = "distribution", required = false, defaultValue = "xx") String distribution,
											@RequestParam(value = "name",       required = false, defaultValue = "xx") String name,
											@RequestParam(value = "dbSave",     required = false, defaultValue = "true") boolean dbSave) {

		GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand,
											maxX, maxY, distribution, name, dbSave);

		List<Node> n = generator.generateNodes(cfg);
		Nodes nodes = new Nodes(name);
		nodes.setNodes(n);
		
		if(cfg.isDbSave())
			nodeService.save(nodes);

		return new ResponseEntity<Object>(nodes, HttpStatus.OK);
	}
}