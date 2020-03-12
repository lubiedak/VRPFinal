package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Problem;
import lombok.Data;
import lombok.extern.slf4j.Slf4j;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Service;

import java.io.*;

@Service
@Data
@ConfigurationProperties(prefix = "vrprunner")
@Slf4j
public class VRPRunner {
    String vrpPath;
    String workspaceDir;
    String fileName;
    int caseNo;

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
            log.error(e.getMessage());
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
            log.error(e.getMessage());
        }
        return f.getAbsolutePath();
    }
}
