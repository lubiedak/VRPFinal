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

class CycleCreator {
public:
	CycleCreator();
	virtual ~CycleCreator();

	/**
	 * Responsible for solving TSP in all cycles
	 */
	bool optimize(std::vector<Cycle>& cycles);

	/**
	 * Responsible for creating all optimised cycles
	 * based on problem criteria
	 */
	bool create(Problem& problem);
};

#endif /* SOLVER_CYCLECREATOR_H_ */
