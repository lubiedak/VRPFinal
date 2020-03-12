package com.vrp.forwarder.controller;

import com.vrp.forwarder.model.Node;
import lombok.Data;
import lombok.NonNull;

import java.util.List;

@Data
public class Nodes {
    @NonNull
    String name;
    List<Node> nodes;
}
