package com.vrp.forwarder.view;

import com.vrp.forwarder.model.Node;
import lombok.Data;

@Data
class NodeD {
    private int id;
    private String label;
    private int x;
    private int y;
    private int size;

     NodeD(Node node){
        id = node.getId();
        label = node.getName() + "_" + node.getDemand();
        x = node.getX();
        y = node.getY();
        size = node.getDemand();
    }
}
