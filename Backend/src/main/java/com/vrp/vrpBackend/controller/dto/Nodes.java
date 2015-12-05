package com.vrp.vrpBackend.controller.dto;

import java.util.List;

import com.vrp.vrpBackend.model.Node;

import lombok.Data;
import lombok.NonNull;

@Data public class Nodes {
	@NonNull
	String name;
	List<Node> nodes;
}
