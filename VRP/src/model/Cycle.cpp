/*
 * Cycle.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Cycle.h"

Cycle::Cycle(): id(0), distance(0), demand(0), capacity(0) {
	nodes = std::vector<Node>();
}

Cycle& Cycle::operator =(const Cycle& c) {
	this->id = c.id;
	this->capacity = c.capacity;
	this->demand = c.demand;
	this->distance = c.distance;
	this->nodes = c.nodes;
	return *this;
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

Cycle::Cycle(const Cycle& c) {
	id = c.id;
	distance = c.distance;
	demand = c.demand;
	capacity = c.capacity;
	nodes = c.nodes;
}



bool Cycle::deserialize(std::string allocator) {
	return true;
}
