/**
 * 
 */
package com.vrp.vrpBackend.service.impl;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import com.vrp.vrpBackend.dao.NodeDao;
import com.vrp.vrpBackend.model.Node;
import com.vrp.vrpBackend.service.JenkinsService;
import com.vrp.vrpBackend.service.NodeService;

/**
 * @author lubiedak
 *
 */
@Component
@ConfigurationProperties(prefix = "jenkins")
public class NodeServiceImpl implements NodeService {

	private static final Logger LOG = LoggerFactory.getLogger(JenkinsService.class);
	
	@Autowired
	NodeDao repo;
	
	@Override
	public Node save(Node node) {
		return repo.save(node);
	}

}
