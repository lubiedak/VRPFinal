/*
 * CycleConnector.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleConnector.h"

CycleConnector::CycleConnector(const Problem& problem,
		const std::vector<Cycle>& cycles) :
		problem(problem), cycles(cycles) {

	prepareData();
}

CycleConnector::~CycleConnector() {
	// TODO Auto-generated destructor stub
}

std::vector<Solution> CycleConnector::connect() {


}

void CycleConnector::prepareData() {
	uint16_t biggestDemanderId = problem.getBiggestDemander();

	for(uint16_t i =0; i< cycles.size(); ++i){
		if(cycles[i].contains(biggestDemanderId))
			specialCycles.push_back(new CyclesSet(cycles[i], i, 1));
		else
			baseCycles.push_back(new CyclesSet(cycles[i], i, 1));
	}

}
