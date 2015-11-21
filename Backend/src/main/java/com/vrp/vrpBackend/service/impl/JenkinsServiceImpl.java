/**
 * 
 */
package com.vrp.vrpBackend.service.impl;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;
import org.springframework.web.client.RestTemplate;

import com.vrp.vrpBackend.service.JenkinsService;

/**
 * @author lubiedak
 *
 */
@Component
@ConfigurationProperties(prefix="jenkins")
public class JenkinsServiceImpl implements JenkinsService {

	public String triggerBuild() {
		String url = "http://localhost:8081/job/vrp-simple/build";

		RestTemplate template = new RestTemplate();

		return template.postForObject(url, String.class, String.class);
	}

}
