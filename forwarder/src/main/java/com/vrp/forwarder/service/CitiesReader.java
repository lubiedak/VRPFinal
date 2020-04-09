package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Node;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

@Component
@ConfigurationProperties(prefix = "cities")
public class CitiesReader {

    private String path;

    private static final int COORDS_MULTIPLIER = 50;

    public List<Node> readCities(){
        List<Node> nodes = new ArrayList<>();
        List<String> lines = new ArrayList<>();
        try {
            lines = Files.readAllLines(Path.of(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
        int id = 0;
        for(String line : lines){
            String[] cells = line.split(";");
            nodes.add( Node.builder().name(cells[0])
                           .x((int)(COORDS_MULTIPLIER*Double.valueOf(cells[1])))
                           .y((int)(COORDS_MULTIPLIER*Double.valueOf(cells[2])))
                           .demand(0)
                           .id(id++)
                           .build());
        }
        return nodes;
    }
}
