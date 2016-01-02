/*
 * CycleConnector.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleConnector.h"
#include <cmath>
#include <iostream>

CycleConnector::CycleConnector(const Problem& problem,
		const std::vector<Cycle>& cycles) :
		problem(problem), cycles(cycles) {

	prepareData();
}

CycleConnector::~CycleConnector() {
	// TODO Auto-generated destructor stub
}

std::vector<CyclesSet*> CycleConnector::connect() {

	uint16_t connIteration = 1;
	connected = connect(connIteration, specialCycles);

	uint16_t connectionsNeeded = problem.estimateConnectionsNeeded();

	while (!isSolved(connected)) {
		std::cout<<"Iteration: "<<connIteration<<",Size"<<connected.size()<<std::endl;
		connIteration++;
		connected = connect(connIteration, connected);
	}
	std::cout<<"Iteration: "<<connIteration<<",Size"<<connected.size()<<std::endl;
	return findSolved(connected);
}

void CycleConnector::prepareData() {
	uint16_t biggestDemanderId = problem.getBiggestDemander();

	for (uint16_t i = 0; i < cycles.size(); ++i) {
		if (cycles[i].contains(biggestDemanderId))
			specialCycles.push_back(new CyclesSet(cycles[i], i, 1));
		else
			baseCycles.push_back(new CyclesSet(cycles[i], i, 1));
	}
	allNodesConnected = uint32_t(pow(2.0, problem.size()) - 1);
}

std::vector<CyclesSet*> CycleConnector::connect(uint16_t it,
		const std::vector<CyclesSet*>& actualCycleSets) {

	std::vector<CyclesSet*> connected;

	for (uint16_t i = 0; i < actualCycleSets.size(); ++i) {
		for (uint16_t j = 0; j < baseCycles.size(); ++j) {
			if (0 == (actualCycleSets[i]->id & baseCycles[j]->id)) {
				uint32_t id = actualCycleSets[i]->id | baseCycles[j]->id;
				uint16_t distance = baseCycles[j]->distance + actualCycleSets[i]->distance;

				if(shortestConnections.find(id) == shortestConnections.end()){
					shortestConnections[id] = distance;
					CyclesSet* cycleSet = new CyclesSet(id, distance, it + 1);
					for (int k = 0; k < it + 1; k++) {
						cycleSet->cycles[k] = actualCycleSets[i]->cycles[k];
					}

					cycleSet->cycles[it] = baseCycles[j]->cycles[0];
					connected.push_back(cycleSet);
				}else if(shortestConnections.at(id) > distance)
				{
					shortestConnections[id] = distance;

					CyclesSet* cycleSet = new CyclesSet(id, distance, it + 1);
					for (int k = 0; k < it + 1; k++) {
						cycleSet->cycles[k] = actualCycleSets[i]->cycles[k];
					}

					cycleSet->cycles[it] = baseCycles[j]->cycles[0];
					connected.push_back(cycleSet);
				}
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

std::vector<CyclesSet*> CycleConnector::findSolved(
		const std::vector<CyclesSet*>& actualCycleSets) {

	std::vector<CyclesSet*> connected;

	for (auto cs : actualCycleSets) {
		if ((cs->id & allNodesConnected) == allNodesConnected) {
			connected.push_back(cs);
		}
	}
	return connected;
}
