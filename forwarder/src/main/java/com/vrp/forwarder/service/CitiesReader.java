package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Node;
import lombok.Getter;
import lombok.Setter;
import lombok.extern.slf4j.Slf4j;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

@Component
@ConfigurationProperties(prefix = "cities")
@Slf4j
public class CitiesReader {
    @Setter
    private String path;

    private static final int COORDS_MULTIPLIER = 50;

    @Getter
    private List<Node> cities;

    public void readCities(){
        if(cities.size() > 0)
            return;

        cities = new ArrayList<>();
        List<String> lines = new ArrayList<>();
        try {
            lines = Files.readAllLines(Path.of(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
        int id = 0;
        for(String line : lines.subList(3,lines.size())){
            String[] cells = line.split(";");
            cities.add(Node.builder().name(cells[0])
                           .x((int)(COORDS_MULTIPLIER*Double.valueOf(cells[2])))
                           .y((int)(COORDS_MULTIPLIER*Double.valueOf(cells[1])))
                           .demand(0)
                           .distance_id(id)
                           .id(id++)
                           .build());
        }
        log.info(cities.toString());
    }
}
