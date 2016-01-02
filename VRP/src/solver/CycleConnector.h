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

	std::vector<CyclesSet*> connect();

	const std::vector<Solution>& getSolutions() const {return solutions;}

private:
	const Problem& problem;
	const std::vector<Cycle>& cycles;
	std::vector<CyclesSet*> specialCycles;
	std::vector<CyclesSet*> baseCycles;
	std::vector<CyclesSet*> connected;

	std::map<uint32_t, uint16_t> shortestConnections;

	std::vector<Solution> solutions;
	uint32_t allNodesConnected;

	void prepareData();
	std::vector<CyclesSet*> connect(uint16_t it, const std::vector<CyclesSet*>& actualCycleSets);
	std::vector<CyclesSet*> findSolved(const std::vector<CyclesSet*>& actualCycleSets);
	bool isSolved(const std::vector<CyclesSet*>& connected);
	void addCyclesSet(std::vector<CyclesSet*>& connected, CyclesSet& actualCycleSet, CyclesSet& baseCycle,
			uint16_t distance, uint32_t id, uint16_t it);
	void transformCycleSetsToSolutions(const std::vector<CyclesSet*>& connected);
};

#endif /* SOLVER_CYCLECONNECTOR_H_ */
