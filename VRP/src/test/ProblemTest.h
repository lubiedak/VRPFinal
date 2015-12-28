/*
 * ProblemTest.h
 *
 *  Created on: 18 Dec 2015
 *      Author: lubiedak
 */

#ifndef TEST_PROBLEMTEST_H_
#define TEST_PROBLEMTEST_H_

#include "../model/Problem.h"

#include "../solver/CycleCreator.h"
#include "resources/ProblemsForTest.h"


bool DistancesCreation_TEST(bool silentMode) {
	Problem p = Problem(Criteria(0,0,0), Node());
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
	params.nodes = 20;

	Criteria c(1000,1000,5,500,0,2);

	Problem p = createRandomProblem(c, params);

	CycleCreator cc(p);
	cc.create();
	return true;
}

bool Problem5Nodes_TEST(bool silentMode){
	Problem p = problem5Nodes();
	CycleCreator cc(p);
	return 25 == cc.create();
}



#endif /* TEST_PROBLEMTEST_H_ */
