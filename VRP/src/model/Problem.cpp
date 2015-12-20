/*
 * Problem.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Problem.h"
#include <math.h>
#include <iostream>

Problem::Problem(Criteria criteria, Node depot) :
		criteria(criteria), depot(depot) {
	std::cout << "WARNING: Problem creation. Nodes not specified." << std::endl;
	analyze();
}

Problem::Problem(Criteria criteria, Node depot, std::vector<Node> nodes) :
		criteria(criteria), depot(depot), nodes(nodes) {
	std::cout << "WARNING: Problem creation. Distances not specified. Counting defaults"
			  << std::endl;
	generateDistances();
	analyze();
}

Problem::Problem(Criteria criteria, Node depot, std::vector<Node> nodes,
		std::vector<std::vector<uint16_t> > distances) :
		criteria(criteria), depot(depot), nodes(nodes), distances(distances) {
	analyze();
}

void Problem::analyze() {
	biggestDemander = findBiggestDemander();
	demandsSum = sumDemands();
}

uint16_t Problem::findBiggestDemander() {
	uint16_t bigDemand = 0;
	uint16_t demander = 0;
	for (uint16_t i = 0; i < nodes.size(); ++i) {
		if (nodes[i].getDemand() > bigDemand) {
			bigDemand = nodes[i].getDemand();
			demander = i;
		}
	}
	return demander;
}

void Problem::generateDistances() {
	distances = std::vector<std::vector<unsigned short> >(nodes.size(),
			std::vector<unsigned short>(nodes.size()));
	for (unsigned i = 0; i < nodes.size(); ++i) {
		for (unsigned j = 0; j < nodes.size(); ++j) {
			distances[i][j] = (int) sqrt(
					  pow(0.0 + nodes[i].getX() - nodes[j].getX(), 2.0)
					+ pow(0.0 + nodes[i].getY() - nodes[j].getY(), 2.0));
		}
	}
}



uint16_t Problem::sumDemands() {
	uint16_t demand = 0;
	for (uint16_t i = 0; i < nodes.size(); ++i) {
		demand += nodes[i].getDemand();
	}
	return demand;
}

