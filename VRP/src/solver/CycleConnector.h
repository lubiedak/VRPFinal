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
#include "Solution.h"



class CycleConnector {
public:
	CycleConnector(const Problem& problem, const std::vector<Cycle>& cycles);
	virtual ~CycleConnector();

	void connect();

	Solution getSolution() const {return solution;}

private:
	const Problem& problem;
	const std::vector<Cycle>& cycles;
	std::vector<CyclesSet*> specialCycles;
	std::vector<CyclesSet*> baseCycles;

	std::map<uint32_t, CyclesSet*> connections;

	Solution solution;
	uint32_t allNodesConnected;

	void prepareData();

	void connectMap(uint16_t it);
	bool fullyConnected();

	void addCyclesSetToMap(CyclesSet& actualCycleSet, CyclesSet& baseCycle,
				uint16_t distance, uint32_t id, uint16_t it);

	void transformCycleSetsToSolutions(const std::vector<CyclesSet*>& connected);
};

#endif /* SOLVER_CYCLECONNECTOR_H_ */
