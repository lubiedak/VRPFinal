/*
 * ProblemsForTest.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef TEST_RESOURCES_PROBLEMSFORTEST_H_
#define TEST_RESOURCES_PROBLEMSFORTEST_H_

#include <vector>
#include <stdlib.h>
#include <time.h>

#include "../../model/Criteria.h"
#include "../../model/Node.h"
#include "../../model/Problem.h"

struct ProblemGenParams {
	uint16_t nodes;
	uint16_t maxX;
	uint16_t maxY;
	uint16_t minDemand;
	uint16_t maxDemand;
};

Problem problem1() {

	Criteria criteria = Criteria(1000, 20000, 5);

	std::vector<Node> nodes = std::vector<Node>();
	nodes.push_back(Node(0, "Depot", 0, 0, 0));
	nodes.push_back(Node(1, "X1", 0, 0, 0));

	Problem problem = Problem();
	return problem;

}

Problem createRandomProblem(Criteria criteria, ProblemGenParams p) {
	Problem problem;
	problem.setCriteria(criteria);
	srand(time(NULL));
	for (uint16_t i = 0; i < p.nodes; ++i) {
		Node n = Node(i, std::string("rand"),
				rand() % p.maxX,
				rand() % p.maxY,
				p.minDemand + rand() % (p.maxDemand - p.minDemand));
		problem.addNode(n);
	}
	problem.generateDistances();
	return problem;
}

#endif /* TEST_RESOURCES_PROBLEMSFORTEST_H_ */
