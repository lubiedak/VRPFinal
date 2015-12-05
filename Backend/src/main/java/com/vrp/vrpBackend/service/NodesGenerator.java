package com.vrp.vrpBackend.service;

import java.util.List;

import com.vrp.vrpBackend.model.GeneratorCfg;
import com.vrp.vrpBackend.model.Node;

public interface NodesGenerator {

	List<Node> generateNodes(GeneratorCfg cfg);
}
