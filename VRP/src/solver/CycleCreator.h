/*
 * CycleCreator.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_CYCLECREATOR_H_
#define SOLVER_CYCLECREATOR_H_

#include <stdint.h>
#include <vector>

#include "../model/Criteria.h"
#include "../model/Cycle.h"
#include "../model/Node.h"
#include "../model/Problem.h"
#include "PermutationGen.h"


class CycleCreator {
public:
	CycleCreator(const Problem& p);
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
	const Problem& problem;

	uint32_t countN();
	std::vector<uint32_t> countPossibleCycles();
	uint32_t NumberOfSetBits(int i);
	uint16_t SumDemand( uint32_t set, const std::vector<Node>& nodes);
};

#endif /* SOLVER_CYCLECREATOR_H_ */
