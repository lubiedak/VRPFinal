/*
 * Cycle.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Cycle.h"

Cycle::Cycle() {
	id = 0;
	distance = 0;
	demand = 0;
	capacity = 0;
}

Cycle::~Cycle() {
	// TODO Auto-generated destructor stub
}

std::string Cycle::toString() {
	std::stringstream oss;
	oss << std::string("class=Cycle");
	oss << delimiter << "id" << mapDelimiter << id;
	oss << delimiter << "distance" << mapDelimiter << distance;
	oss << delimiter << "demand"   << mapDelimiter << demand;
	oss << delimiter << "capacity" << mapDelimiter << capacity;
	for(auto n : nodes){
		oss << delimiter << "nodeId" << mapDelimiter << n.getId();
	}

	return oss.str();
}

std::string Cycle::serialize() {
	return toString();
}

bool Cycle::deserialize(std::string allocator) {
	return true;
}
