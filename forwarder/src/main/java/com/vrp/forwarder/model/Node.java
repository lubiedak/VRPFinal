package com.vrp.forwarder.model;

import lombok.Data;
import lombok.NonNull;

@Data
public class Node {

	private int id;
	@NonNull
	private String name;
	private int x;
	private int y;
	private int demand;
	
	private double angle;

	@Override
	public String toString() {
		return "class=Node,id=" + id
				+ ",name=" + name
				+ ",x=" + x
				+ ",y=" + y
				+ ",demand=" + demand
				+ ",angle=" + angle;
	}
}
