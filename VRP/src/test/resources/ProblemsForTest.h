/*
 * ProblemsForTest.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef TEST_RESOURCES_PROBLEMSFORTEST_H_
#define TEST_RESOURCES_PROBLEMSFORTEST_H_

#include "../../model/Criteria.h"
#include "../../model/Problem.h"

struct ProblemGenParams {
	uint16_t nodes;
	uint16_t maxX;
	uint16_t maxY;
	uint16_t minDemand;
	uint16_t maxDemand;
};

Problem problem5Nodes();
Problem problem6Nodes();
Problem problem10Nodes();
Problem problem20Nodes();
Problem createRandomProblem(Criteria criteria, ProblemGenParams p);

#endif /* TEST_RESOURCES_PROBLEMSFORTEST_H_ */
