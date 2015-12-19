/*
 * Problem.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Problem.h"
#include <math.h>

Problem::Problem() {
	// TODO Auto-generated constructor stub

}

Problem::~Problem() {
	// TODO Auto-generated destructor stub
}

void Problem::analyze() {
	biggestDemander = findBiggestDemander();
	demandsSum = sumDemands();
}

unsigned Problem::findBiggestDemander() {
	unsigned bigDemand = 0;
	unsigned demander = 0;
	for (unsigned i = 0; i < nodes.size(); ++i) {
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

unsigned Problem::sumDemands() {
	unsigned demand = 0;
	for (unsigned i = 0; i < nodes.size(); ++i) {
		demand += nodes[i].getDemand();
	}
	return demand;
}
