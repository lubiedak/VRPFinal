package com.vrp.forwarder.view;

import com.vrp.forwarder.model.Cycle;
import lombok.Builder;
import lombok.Data;

import java.util.ArrayList;
import java.util.List;

@Data
@Builder
class Edge {
    String id;
    int source;
    int target;
    int size;
    String color;

    static List<Edge> edges(Cycle c){
        String color = "#"+(int)(Math.random() * 0x1000000);
        int[] nodes = c.getNodes();
        List<Edge> edges = new ArrayList<>();

        int i;
        for(i=0; i<nodes.length-1; i++){
            edges.add(Edge.builder()
                          .id(nodes[i] + "_" + nodes[i+1])
                          .source(nodes[i])
                          .target(nodes[i+1])
                          .color(color)
                          .size(20)
                          .build());
        }
        edges.add(Edge.builder()
                      .id(nodes[i] + "_" + nodes[0])
                      .source(nodes[i])
                      .target(nodes[0])
                      .color(color)
                      .size(20)
                      .build());

        return edges;
    }
}
