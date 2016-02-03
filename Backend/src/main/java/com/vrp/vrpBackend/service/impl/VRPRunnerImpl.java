package com.vrp.vrpBackend.service.impl;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.springframework.stereotype.Component;

import com.vrp.vrpBackend.model.Problem;
import com.vrp.vrpBackend.service.VRPRunner;

@Component
public class VRPRunnerImpl implements VRPRunner {

	@Override
	public String run(Problem p) {
		String s = execute();
		System.out.println(s);
		return s;
	}
	
	private String execute(){
		StringBuffer output = new StringBuffer();
		String command = "/home/lubiedak/workspace/VRPFinalRepo/VRP/Release/VRPCore2.0";

		Process p;
		try {
			p = Runtime.getRuntime().exec(command);
			p.waitFor();
			BufferedReader reader = 
                            new BufferedReader(new InputStreamReader(p.getInputStream()));

                        String line = "";			
			while ((line = reader.readLine())!= null) {
				output.append(line + "\n");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return output.toString();
	}

}
