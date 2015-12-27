/*
 * Cycle.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Cycle.h"

Cycle::Cycle() : id(0), distance(0), demand(0), capacity(0) {
	nodes = std::vector<Node>();
	membersCount = 5;
}

Cycle& Cycle::operator =(const Cycle& c) {
	this->id = c.id;
	this->capacity = c.capacity;
	this->demand = c.demand;
	this->distance = c.distance;
	this->nodes = c.nodes;
	this->membersCount = c.membersCount;
	return *this;
}

Cycle::Cycle(const Cycle& c) {
	id = c.id;
	distance = c.distance;
	demand = c.demand;
	capacity = c.capacity;
	nodes = c.nodes;
	membersCount = c.membersCount;
}

Cycle::~Cycle() {
	// TODO Auto-generated destructor stub
}

std::string Cycle::toString() {
	std::stringstream oss;
	oss << std::string("class=Cycle");
	oss << delimiter << "id" << mapDelimiter << id;
	oss << delimiter << "distance" << mapDelimiter << distance;
	oss << delimiter << "demand" << mapDelimiter << demand;
	oss << delimiter << "capacity" << mapDelimiter << capacity;
	int i = 0;
	for (auto n : nodes) {
		oss << delimiter << "nodeId" << i++ << mapDelimiter << n.getId();
	}

	return oss.str();
}

std::string Cycle::serialize() {
	return toString();
}


bool Cycle::deserialize(std::string allocator) {
	return true;
}

uint16_t Cycle::selfOptimize( const std::vector<std::vector<uint16_t> >& distances,
							  const std::vector<std::vector<int> >& perms) {

	return 0;
}
