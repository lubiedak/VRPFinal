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


class CycleConnector {
public:
	CycleConnector(const Problem& problem, const std::vector<Cycle>& cycles);
	virtual ~CycleConnector();


private:
	const std::vector<Cycle>& cycles;
	std::vector<CyclesSet> specialCycles;
	std::vector<CyclesSet> baseCycles;

	const Problem& problem;

};

#endif /* SOLVER_CYCLECONNECTOR_H_ */
