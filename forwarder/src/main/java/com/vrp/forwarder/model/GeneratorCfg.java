package com.vrp.forwarder.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NonNull;
import lombok.RequiredArgsConstructor;

import javax.validation.constraints.Max;

@Data
@AllArgsConstructor
@RequiredArgsConstructor
public class GeneratorCfg {
	@Max(200)
	private final int nodesCount;
	private final int minDemand;
	private final int maxDemand;
	private int maxX = 1000;
	private int maxY = 1000;

}
