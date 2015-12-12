package com.vrp.vrpBackend.model;

import java.util.List;

import lombok.Data;

@Data public class Cycle {

	private List<Node> nodes;
	private int length;
	private int totalDemand;
	private int capacity;
	
}
