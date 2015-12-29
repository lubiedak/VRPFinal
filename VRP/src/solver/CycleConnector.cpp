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

	std::vector<CyclesSet*> connected;
	for (uint16_t i = 0; i < specialCycles.size(); ++i) {
		for (uint16_t j = 0; j < baseCycles.size(); ++j) {
			if(0 == (specialCycles[i]->id & baseCycles[j]->id)){
				uint32_t id = specialCycles[i]->id | baseCycles[j]->id;

				CyclesSet* cycleSet = new CyclesSet(id, baseCycles[j]->distance + specialCycles[i]->distance, 2);
				cycleSet->cycles[0] = specialCycles[i]->cycles[0];
				cycleSet->cycles[1] = baseCycles[j]->cycles[0];
				connected.push_back(cycleSet);

			}
		}
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
