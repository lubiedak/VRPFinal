/*
 * Cycle.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Cycle.h"

#include <cstdint>
#include <sstream>

#include "../solver/PermutationGen.h"

const uint32_t permBorders[] = {0,1,2,6,24,120,720,5040,40320};

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
							  std::vector<std::vector<int> >& perms) {

	if(nodes.size()-1 == 0)
		return 0;
	checkPermSize(perms);
	distance = countMinimumDistance(distances, perms);

	return distance;
}

void Cycle::checkPermSize(std::vector<std::vector<int>>& perms){
	uint16_t size = nodes.size()-1;
	if(size > perms[0].size()){
		PermutationGen<int> permGen(size);
		perms = permGen.getFullPermTable();
	}
}

uint16_t Cycle::countMinimumDistance(const std::vector<std::vector<uint16_t> >& distances,
									 const std::vector<std::vector<int> >& perms) {
	uint16_t size = nodes.size()-1;
	uint16_t minDistance = 20000;
	uint16_t bestPerm = 0;
	uint16_t dist = 0;

	for(uint32_t i = 0; i < permBorders[size]; ++i){
		// depot and first
		dist =  distances[nodes[0].getId()][1 + nodes[perms[i][0]].getId()];
		//last and depot
		dist += distances[1 + nodes[perms[i][size-1]].getId()][nodes[0].getId()];

		for(int j = 1; j < size; ++j){
			dist += distances[1 + nodes[perms[i][j-1]].getId()][1 + nodes[perms[i][j]].getId()];
		}
		if(dist < minDistance){
			minDistance = dist;
			bestPerm = i;
		}
	}

	// change nodes order
	std::vector<Node> nodesCopy(nodes.begin(), nodes.end());
	for(uint16_t i  = 1; i < size; i++){
		nodes[i] = nodesCopy[perms[bestPerm][i-1]];
	}

	return minDistance;
}
