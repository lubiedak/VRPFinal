package com.vrp.forwarder.model;

import lombok.Builder;
import lombok.Data;
import lombok.NonNull;

@Data
@Builder(toBuilder = true)
public class Node {

	private int id;
	@NonNull
	private String name;
	private int x;
	private int y;
	private int demand;
	private double angle;
}
