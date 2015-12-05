package com.vrp.vrpBackend.model;

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
}
