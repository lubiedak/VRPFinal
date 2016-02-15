package com.vrp.vrpBackend.model;

import lombok.Data;

@Data public class Criteria {
	int minNodes;
	int maxNodes;
	int minCapacity;
	int maxCapacity;
	int minDistance;
	int maxDistance;
	
	public Criteria(){
		minNodes = 1;
		maxNodes = 5;
		minCapacity = 1000;
		maxCapacity = 400;
		minDistance = 5000;
		maxDistance = 0;
	}
	
	@Override
	public String toString() {
		return "class=Criteria,minNodes=" + minNodes + ", maxNodes=" + maxNodes + ", minCapacity=" + minCapacity
				+ ", maxCapacity=" + maxCapacity + ", minDistance=" + minDistance + ", maxDistance=" + maxDistance;
	}
}
