package com.vrp.forwarder.model;

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
		minCapacity = 400;
		maxCapacity = 1000;
		minDistance = 0;
		maxDistance = 5000;
	}
	
	@Override
	public String toString() {
		return "class=Criteria,minNodes=" + minNodes + ",maxNodes=" + maxNodes + ",minCapacity=" + minCapacity
				+ ",maxCapacity=" + maxCapacity + ",minDistance=" + minDistance + ",maxDistance=" + maxDistance;
	}
}
