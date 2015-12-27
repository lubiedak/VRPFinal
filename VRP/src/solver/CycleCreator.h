/*
 * CycleCreator.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_CYCLECREATOR_H_
#define SOLVER_CYCLECREATOR_H_

#include <vector>

#include "../model/Cycle.h"
#include "../model/Problem.h"
#include "PermutationGen.h"
#include <stdint.h>

class CycleCreator {
public:
	CycleCreator(Problem p, Criteria c);
	virtual ~CycleCreator();

	/**
	 * Responsible for solving TSP in all cycles
	 */
	bool optimize(std::vector<Cycle>& cycles);

	/**
	 * Responsible for creating all optimised cycles
	 * based on problem criteria
	 */
	bool create();

private:
	PermutationGen<int> permGen;
	Problem problem;
	Criteria criteria;

	uint32_t countN(Problem p, unsigned maxNodes);
	std::vector<uint32_t> countPossibleCycles();
	uint32_t NumberOfSetBits(int i);
	uint16_t SumDemand( uint32_t set, const std::vector<Node>& nodes);
};

#endif /* SOLVER_CYCLECREATOR_H_ */
