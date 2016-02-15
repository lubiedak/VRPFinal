package com.vrp.vrpBackend.service.impl;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import com.vrp.vrpBackend.model.Problem;
import com.vrp.vrpBackend.service.VRPRunner;

@Component
@ConfigurationProperties(prefix = "vrpRunner")
public class VRPRunnerImpl implements VRPRunner {

	String vrpPath;
	
	@Override
	public String run(Problem p) {
		String s = execute();
		System.out.println(s);
		System.out.println(p);
		return s;
	}

	private String execute() {
		StringBuffer output = new StringBuffer();
		String command = vrpPath;

		Process p;
		try {
			p = Runtime.getRuntime().exec(command);
			p.waitFor();
			BufferedReader reader = new BufferedReader(new InputStreamReader(p.getInputStream()));

			String line = "";
			while ((line = reader.readLine()) != null) {
				output.append(line + "\n");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
		return output.toString();
	}

}
