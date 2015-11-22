/**
 * 
 */
package com.vrp.vrpBackend.service.impl;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;
import org.springframework.web.client.RestTemplate;

import com.vrp.vrpBackend.service.JenkinsService;

/**
 * @author lubiedak
 *
 */
@Component
@ConfigurationProperties(prefix = "jenkins")
public class JenkinsServiceImpl implements JenkinsService {

	private static final Logger LOG = LoggerFactory.getLogger(JenkinsService.class);

	private String url;
	private String job;
	private String buildTrigger;

	@Override
	public String triggerBuild() {
		RestTemplate template = new RestTemplate();

		return template.postForObject(url + job + buildTrigger, String.class, String.class);
	}

	@Override
	public String getJenkinsInfo() {
		return toString();
	}

	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	public String getJob() {
		return job;
	}

	public void setJob(String job) {
		this.job = job;
	}

	public String getBuildTrigger() {
		return buildTrigger;
	}

	public void setBuildTrigger(String buildTrigger) {
		this.buildTrigger = buildTrigger;
	}

	@Override
	public String toString() {
		return "JenkinsServiceImpl [url=" + url + ", job=" + job + ", buildTrigger=" + buildTrigger + "]";
	}
}
