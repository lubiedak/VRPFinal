package com.vrp.forwarder.controller;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.vrp.forwarder.model.Criteria;
import com.vrp.forwarder.model.GeneratorCfg;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import com.vrp.forwarder.service.NodesGenerator;
import com.vrp.forwarder.service.VRPRunner;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequiredArgsConstructor
public class NodeController {

    private static final String URL = "api/v1/node";

    private final NodesGenerator generator;

    private final VRPRunner vrpRunner;


    @RequestMapping(value = URL, method = RequestMethod.GET)
    public ResponseEntity<Object> endpoints() {
        return new ResponseEntity<Object>(generate(0, 0, 0, 0, 0, "text", "text", false), HttpStatus.OK);
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

        Problem p = new Problem();
        p.setCriteria(new Criteria());
        p.setNodes(n);

        p.sortNodes();
        n = p.getNodes();
        n.forEach(node -> System.out.println(node));

        return new ResponseEntity<Object>(nodes, HttpStatus.OK);
    }

    @RequestMapping(value = URL + "/generateAndSolve", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity<Object> generateAndSolve( @RequestParam int nodesCount,
                                                    @RequestParam int minDemand,
                                                    @RequestParam int maxDemand,
                                                    @RequestParam int maxX,
                                                    @RequestParam int maxY,
                                                    @RequestParam(required=false) String distribution,
                                                    @RequestParam(required=false, defaultValue="xx") String name,
                                                    @RequestParam(required=false, defaultValue="false") boolean dbSave) throws JsonProcessingException {

        GeneratorCfg cfg = new GeneratorCfg(nodesCount, minDemand, maxDemand,
                                            maxX, maxY, distribution, name, dbSave);

        List<Node> nodes = generator.generateNodes(cfg);
        Problem p = new Problem();
        p.setCriteria(new Criteria());
        p.setNodes(nodes);
        p.sortNodes();


        return new ResponseEntity<Object>(vrpRunner.run(p), HttpStatus.OK);
    }
}
