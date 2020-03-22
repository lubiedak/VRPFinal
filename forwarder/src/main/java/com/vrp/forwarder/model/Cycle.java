package com.vrp.forwarder.model;

import lombok.Data;

import java.util.List;

@Data
public class Cycle {

	private int[] nodes;
	private int length;
	private int totalDemand;
	private int capacity;
	
}
