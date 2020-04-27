package com.vrp.forwarder.model;

import org.springframework.stereotype.Component;

import java.util.List;

@Component
public class ProblemContainer {
    List<Problem> problems;
    List<Node> depots;
    String config;
}
