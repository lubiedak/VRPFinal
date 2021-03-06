package com.vrp.vrpBackend.model;

import javax.validation.constraints.Max;

import lombok.Data;
import lombok.NonNull;

@Data
public class GeneratorCfg {
	@Max(200)
	private int nodesCount;
	private int minDemand;
	private int maxDemand;
	private int maxX;
	private int maxY;

	@NonNull
	private String distribution;
	@NonNull
	private String name;
	private boolean dbSave;

	public GeneratorCfg(int nodesCount, int minDemand, int maxDemand, int maxX, int maxY, String distribution,
			String name, boolean dbSave) {
		super();
		this.nodesCount = nodesCount;
		this.minDemand = minDemand;
		this.maxDemand = maxDemand;
		this.maxX = maxX;
		this.maxY = maxY;
		this.distribution = distribution;
		this.name = name;
		this.dbSave = dbSave;
	}
}
