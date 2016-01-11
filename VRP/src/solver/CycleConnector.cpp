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

void CycleConnector::connect() {
	uint16_t connIteration = 1;
	connectMap(connIteration);
	std::cout<<"iteration: "<<connIteration<<" connected: "<<shortestConnected.size()<<std::endl;

	while (!fullyConnected()) {
		connIteration++;
		connectMap(connIteration);
		std::cout<<"iteration: "<<connIteration<<" connected: "<<shortestConnected.size()<<std::endl;
	}
	std::vector<CyclesSet*> connected = findSolved();
	transformCycleSetsToSolutions(connected);
}

void CycleConnector::prepareData() {
	uint16_t biggestDemanderId = problem.getBiggestDemander();

	for (uint16_t i = 0; i < cycles.size(); ++i) {
		if (cycles[i].contains(biggestDemanderId)){
			specialCycles.push_back(new CyclesSet(cycles[i], i, 1));
			shortestConnected[cycles[i].getId()] = new CyclesSet(cycles[i], i, 1);
		}else{
			baseCycles.push_back(new CyclesSet(cycles[i], i, 1));
		}
	}
	allNodesConnected = uint32_t(pow(2.0, problem.size()) - 1);
}

void CycleConnector::connectMap(uint16_t it) {

	std::map<uint32_t, CyclesSet*> newConnected = shortestConnected;
	uint32_t size = newConnected.size();
	uint32_t step = size/4;
	uint32_t i = 0;

	bool foundFirstFull = false;

	for (auto conn : newConnected) {
		++i;
		for (uint16_t j = 0; j < baseCycles.size(); ++j) {
			//IF They don't have common Node
			if ( 0 == (conn.second->id & baseCycles[j]->id) ) {
				if(i > step){
					std::cout<<i<<" from "<<size<<" analyzed."<<std::endl;
					step+=step;
				}
				uint32_t id = conn.second->id | baseCycles[j]->id;

				if(!foundFirstFull && id == allNodesConnected)
					foundFirstFull = true;

				if(foundFirstFull == (id == allNodesConnected)){
					uint16_t distance = baseCycles[j]->distance
							+ conn.second->distance;

					if (shortestConnected.find(id) == shortestConnected.end()) {

						addCyclesSetToMap(*conn.second, *baseCycles[j],	distance, id, it);
						if(id == allNodesConnected)
						std::cout<<"NE: "<<shortestConnected.at(id)->toString()<<std::endl;

					} else if (shortestConnected.at(id)->distance > distance) {

						addCyclesSetToMap(*conn.second, *baseCycles[j],	distance, id, it);
						if(id == allNodesConnected)
							std::cout<<"DE: "<<shortestConnected.at(id)->toString()<<std::endl;
					}
				}
			}
		}
	}
	//return connected;
}

std::vector<CyclesSet*> CycleConnector::findSolved() {
	std::vector<CyclesSet*> connected;

	for (auto cs : shortestConnected) {
		if ((cs.first & allNodesConnected) == allNodesConnected) {
			connected.push_back(cs.second);
		}
	}
	return connected;
}


void CycleConnector::addCyclesSetToMap(CyclesSet& actualCycleSet, CyclesSet& baseCycle, uint16_t distance,
		uint32_t id, uint16_t it) {

	CyclesSet* cycleSet = new CyclesSet(id, distance, it + 1);
	for (int k = 0; k < it + 1; k++) {
		cycleSet->cycles[k] = actualCycleSet.cycles[k];
	}

	cycleSet->cycles[it] = baseCycle.cycles[0];
	shortestConnected[id] = cycleSet;
}

bool CycleConnector::fullyConnected() {
	return shortestConnected.find(allNodesConnected) != shortestConnected.end();
}

void CycleConnector::transformCycleSetsToSolutions(const std::vector<CyclesSet*>& connected) {
	for(CyclesSet* cs : connected){
		solutions.push_back(Solution(*cs, cycles));
	}
}

