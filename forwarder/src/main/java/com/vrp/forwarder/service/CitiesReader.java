package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Node;
import lombok.Getter;
import lombok.Setter;
import lombok.extern.slf4j.Slf4j;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;
import org.springframework.util.StringUtils;

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

    private List<Node> cities;

    public List<Node> getCities(){
        if(cities == null) {
            readCities();
        }
        return cities;
    }

    private void readCities(){
        cities = new ArrayList<>();
        List<String> lines = new ArrayList<>();
        try {
            lines = Files.readAllLines(Path.of(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
        int id = 0;
        for (String line : lines.subList(3, lines.size())) {
            String[] cells = line.split(";");
            cities.add(Node.builder()
                           .name(cells[0])
                           .x((int) (COORDS_MULTIPLIER * Double.valueOf(cells[2])))
                           .y((int) (COORDS_MULTIPLIER * Double.valueOf(cells[1])))
                           .region(cells[3])
                           .group(cells[4])
                           .demand(0)
                           .depot(!StringUtils.isEmpty(cells[0]) && cells[0].equals(cells[4]))
                           .distance_id(id)
                           .id(id++)
                           .build());
        }
    }
}
