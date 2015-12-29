/*
 * CycleConnector.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_CYCLECONNECTOR_H_
#define SOLVER_CYCLECONNECTOR_H_

#include <vector>

#include "../model/Cycle.h"
#include "CyclesSet.h"
#include "../model/Problem.h"
#include "../model/Solution.h"



class CycleConnector {
public:
	CycleConnector(const Problem& problem, const std::vector<Cycle>& cycles);
	virtual ~CycleConnector();

	std::vector<Solution> connect();


private:
	const std::vector<Cycle>& cycles;
	std::vector<CyclesSet*> specialCycles;
	std::vector<CyclesSet*> baseCycles;

	const Problem& problem;
	std::vector<Solution> solutions;

	void prepareData();
};

#endif /* SOLVER_CYCLECONNECTOR_H_ */
