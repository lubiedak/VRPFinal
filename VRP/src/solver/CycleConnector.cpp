/*
 * CycleConnector.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleConnector.h"
#include <cmath>

CycleConnector::CycleConnector(const Problem& problem,
		const std::vector<Cycle>& cycles) :
		problem(problem), cycles(cycles) {

	prepareData();
}

CycleConnector::~CycleConnector() {
	// TODO Auto-generated destructor stub
}

void CycleConnector::connect() {

	uint16_t connIteration = 1;
	connected = connect(connIteration, specialCycles);
	connIteration++;

	uint16_t connectionsNeeded = problem.estimateConnectionsNeeded();

	while (connIteration <= connectionsNeeded) {
		if (isSolved(connected))
			break;
		connected = connect(connIteration, connected);
		connIteration++;
	}

	int a = 2;
}

void CycleConnector::prepareData() {
	uint16_t biggestDemanderId = problem.getBiggestDemander();

	for (uint16_t i = 0; i < cycles.size(); ++i) {
		if (cycles[i].contains(biggestDemanderId))
			specialCycles.push_back(new CyclesSet(cycles[i], i, 1));
		else
			baseCycles.push_back(new CyclesSet(cycles[i], i, 1));
	}
	allNodesConnected = pow(problem.size(), 2.0) - 1;
}

std::vector<CyclesSet*> CycleConnector::connect(uint16_t it,
		const std::vector<CyclesSet*>& actualCycleSets) {

	std::vector<CyclesSet*> connected;

	for (uint16_t i = 0; i < actualCycleSets.size(); ++i) {
		for (uint16_t j = 0; j < baseCycles.size(); ++j) {
			if (0 == (actualCycleSets[i]->id & baseCycles[j]->id)) {
				uint32_t id = actualCycleSets[i]->id | baseCycles[j]->id;

				CyclesSet* cycleSet = new CyclesSet(id,
						baseCycles[j]->distance + actualCycleSets[i]->distance,
						it + 1);
				for(int k = 0; k < it+1; k++){
					cycleSet->cycles[k] = actualCycleSets[i]->cycles[k];
				}

				cycleSet->cycles[it] = baseCycles[j]->cycles[0];
				connected.push_back(cycleSet);
			}
		}
	}
	return connected;
}

bool CycleConnector::isSolved(const std::vector<CyclesSet*>& connected) {

	for (auto cs : connected) {
		if ((cs->id & allNodesConnected) == allNodesConnected) {
			return true;
		}
	}
	return false;
}
