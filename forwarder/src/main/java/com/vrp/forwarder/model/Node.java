package com.vrp.forwarder.model;

import lombok.*;

@Data
@Builder(toBuilder = true)
@AllArgsConstructor
public class Node {
	private final String name;
	private int id;
	private int x;
	private int y;
	private int demand;
	private double angle;

	public Node(String name){
		this.name = name;
	}
}
