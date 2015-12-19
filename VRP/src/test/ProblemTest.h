/*
 * ProblemTest.h
 *
 *  Created on: 18 Dec 2015
 *      Author: lubiedak
 */

#ifndef TEST_PROBLEMTEST_H_
#define TEST_PROBLEMTEST_H_

#include "../model/Problem.h"

bool DistancesCreation_TEST(bool silentMode) {
	Problem p = Problem();
	p.addNode(Node(0,"",0,0,0));
	p.addNode(Node(0,"",3,4,0));

	p.generateDistances();
	std::vector<std::vector<unsigned short>> dist = p.getDistances();
	return dist[0][1] == 5;
}



#endif /* TEST_PROBLEMTEST_H_ */
