package com.vrp.forwarder.model;

import lombok.*;
import lombok.experimental.SuperBuilder;

@Data
@SuperBuilder(toBuilder = true)
@AllArgsConstructor
public class Node {
	private final String name;
	private int id;
	private int distance_id;
	private int x;
	private int y;
	private int demand;
	private double angle;

	//Maybe in seperate class ?
	private String group;
	private String region;
	private boolean depot;

	public Node(String name){
		this.name = name;
	}
}
