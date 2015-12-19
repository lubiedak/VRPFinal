/*
 * ProblemTest.h
 *
 *  Created on: 18 Dec 2015
 *      Author: lubiedak
 */

#ifndef TEST_PROBLEMTEST_H_
#define TEST_PROBLEMTEST_H_

#include "../model/Problem.h"

#include "resources/ProblemsForTest.h"


bool DistancesCreation_TEST(bool silentMode) {
	Problem p = Problem();
	p.addNode(Node(0,"",0,0,0));
	p.addNode(Node(0,"",3,4,0));

	p.generateDistances();
	std::vector<std::vector<unsigned short>> dist = p.getDistances();
	return dist[0][1] == 5;
}

bool RandomProblem_TEST(bool silentMode){
	ProblemGenParams params;
	params.maxDemand = 600;
	params.minDemand = 100;
	params.maxX = 1000;
	params.maxY = 1000;
	params.nodes = 24;

	Criteria c(1000,1000,5);

	Problem p = createRandomProblem(c, params);
	return true;
}



#endif /* TEST_PROBLEMTEST_H_ */
