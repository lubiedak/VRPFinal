package com.vrp.vrpBackend.model;

import java.util.List;

import lombok.Data;

@Data
public class Problem {
	List<Node> nodes;
	Criteria criteria;

	@Override
	public String toString() {
		String str = "";
		str += criteria.toString() + "\n";
		for (Node n : nodes) {
			str += n.toString() + "\n";
		}
		return str;
	}
}
