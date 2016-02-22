package com.vrp.vrpBackend.service.impl;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import com.vrp.vrpBackend.model.Problem;
import com.vrp.vrpBackend.service.JenkinsService;
import com.vrp.vrpBackend.service.VRPRunner;

import lombok.Data;

@Component
@Data
@ConfigurationProperties(prefix = "vrpRunner")
public class VRPRunnerImpl implements VRPRunner {
	private static final Logger LOG = LoggerFactory.getLogger(VRPRunner.class);

	String vrpPath;
	String workspaceDir;
	String fileName;
	int caseNo;

	@Override
	public String run(Problem p) {

		String s = execute(p);
		System.out.println(s);
		return s;
	}

	private String execute(Problem problem) {

		String ioDir = createWorkspaceDirs();
		String inputFile = createInputFile(ioDir, problem);

		StringBuffer output = new StringBuffer();
		String command = vrpPath;
		command += " --inputFile=" + inputFile;
		command += " --outputDir=" + ioDir;

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
			LOG.error(e.getMessage());
		}
		return output.toString();
	}

	private String createWorkspaceDirs() {
		File workspace = new File(workspaceDir);
		int caseNo = workspace.list().length;

		String caseDir = workspaceDir + caseNo + "/";
		File f = new File(caseDir);
		f.mkdirs();
		return caseDir;
	}

	private String createInputFile(String dir, Problem p) {
		File f = new File(dir + fileName);
		try {
			f.createNewFile();
			FileWriter fw = new FileWriter(f);
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(p.toString());
			bw.close();
		} catch (IOException e) {
			LOG.error(e.getMessage());
		}
		return f.getAbsolutePath();
	}
}
