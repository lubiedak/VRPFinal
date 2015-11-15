/**
 * 
 */
package com.vrp.vrpBackend.service.impl;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Component;
import org.springframework.web.client.RestTemplate;

import com.vrp.vrpBackend.service.JenkinsService;

/**
 * @author lubiedak
 *
 */
@Component
public class JenkinsServiceImpl implements JenkinsService{

	public String triggerBuild(){
		String url = "http://localhost:8081/job/vrp-simple/build";

		  RestTemplate template = new RestTemplate();

		  Map<String, String> params = new HashMap<String, String>();

		  String result = template.postForObject(url, String.class, String.class);
		  return result;
    }
	
}
