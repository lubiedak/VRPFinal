/**
 * 
 */
package com.vrp.vrpBackend.service.impl;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

import com.vrp.vrpBackend.model.Cycle;
import com.vrp.vrpBackend.model.Node;
import com.vrp.vrpBackend.service.CycleService;
import com.vrp.vrpBackend.service.JenkinsService;

/**
 * @author lubiedak
 *
 */
@Component
public class CycleServiceImpl implements CycleService {

	private static final Logger LOG = LoggerFactory.getLogger(JenkinsService.class);

	@Override
	public Cycle generateRandom(int n, int maxN) {
		int size = n < maxN ? n : maxN;
		Cycle c = new Cycle();
		List<Node> nodes = new ArrayList<Node>(size);
		Random r = new Random();
		for(int i = 0; i<size; ++i){
			Node node = new Node(""+i);
			node.setId(r.nextInt(maxN));
			nodes.add(node);
		}
		c.setNodes(nodes);
		return c;
	}
	


}
