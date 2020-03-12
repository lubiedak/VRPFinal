package com.vrp.forwarder.model;

import lombok.Data;

import java.util.List;

@Data public class Cycle {

	private List<Node> nodes;
	private int length;
	private int totalDemand;
	private int capacity;
	
}
