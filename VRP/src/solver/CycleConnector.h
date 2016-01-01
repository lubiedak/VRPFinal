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

	void connect();


private:
	const Problem& problem;
	const std::vector<Cycle>& cycles;
	std::vector<CyclesSet*> specialCycles;
	std::vector<CyclesSet*> baseCycles;

	std::vector<Solution> solutions;
	uint32_t allNodesConnected;

	void prepareData();
	std::vector<CyclesSet*> connect(const std::vector<CyclesSet*>& actualCycleSets);
	bool isSolved(const std::vector<CyclesSet*>& connected);
};

#endif /* SOLVER_CYCLECONNECTOR_H_ */
