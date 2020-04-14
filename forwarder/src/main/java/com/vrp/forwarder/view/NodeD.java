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
    private String color;

     NodeD(Node node){
        id = node.getId();
        label = node.getName() + "_" + node.getDemand();
        x = node.getX();
        y = node.getY();
        color = node.getRegion() == null ? "" : "#"+(node.getRegion().hashCode() % 0x100000);
        size = node.getDemand() == 0 ? 40 : node.getDemand();
    }
}
