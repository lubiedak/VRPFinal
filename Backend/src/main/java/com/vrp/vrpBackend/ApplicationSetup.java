package com.vrp.vrpBackend;

import java.net.InetAddress;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

@Component
public class ApplicationSetup {

	private static final Logger LOG = LoggerFactory.getLogger(ApplicationSetup.class);

	/*
	private String username;

	private InetAddress remoteAddress;

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public InetAddress getRemoteAddress() {
		return remoteAddress;
	}

	public void setRemoteAddress(InetAddress remoteAddress) {
		this.remoteAddress = remoteAddress;
	}

	@Override
	public String toString() {
		return username + " : " + remoteAddress;
	}

	@PostConstruct
	public void xxx() {
		LOG.info("Initialized [{}] [{}]", username, remoteAddress);
	}
    */
}
