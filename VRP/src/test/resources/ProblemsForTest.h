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

Problem problem5Nodes() {

	Criteria criteria = Criteria(1000, 20000, 5);

	std::vector<Node> nodes = std::vector<Node>();
	Node depot(0, "Depot", 0, 0, 0);
	nodes.push_back(Node(1, "X1", 10, 60, 301));
	nodes.push_back(Node(2, "X2", 20, 70, 300));
	nodes.push_back(Node(3, "X3", 120, 120, 300));
	nodes.push_back(Node(4, "X4", 120, 130, 300));
	nodes.push_back(Node(5, "X5", 140, 130, 300));

	Problem problem = Problem(criteria, depot, nodes);
	problem.generateDistances();
	return problem;
}

Problem problem6Nodes() {

	Criteria criteria = Criteria(1000, 20000, 5);

	std::vector<Node> nodes = std::vector<Node>();
	Node depot(0, "Depot", 0, 0, 0);
	nodes.push_back(Node(1, "X1", 10, 60, 220));
	nodes.push_back(Node(2, "X2", 20, 70, 220));
	nodes.push_back(Node(3, "X3", 120, 120, 220));
	nodes.push_back(Node(4, "X4", 120, 130, 220));
	nodes.push_back(Node(5, "X5", 140, 130, 220));
	nodes.push_back(Node(6, "X6", 140, 170, 220));

	Problem problem = Problem(criteria, depot, nodes);
	problem.generateDistances();
	return problem;
}

Problem problem10Nodes() {

	Criteria criteria = Criteria(1000, 20000, 5);

	std::vector<Node> nodes = std::vector<Node>();
	Node depot(0, "Depot", 0, 0, 0);
	nodes.push_back(Node(1, "X1", 10, 60, 301));
	nodes.push_back(Node(2, "X2", 20, 70, 300));
	nodes.push_back(Node(3, "X3", 120, 120, 300));
	nodes.push_back(Node(4, "X4", 120, 130, 300));
	nodes.push_back(Node(5, "X5", 140, 130, 300));
	nodes.push_back(Node(6, "X6", 420, 120, 300));
	nodes.push_back(Node(7, "X7", 420, 130, 300));
	nodes.push_back(Node(8, "X8", 440, 130, 300));
	nodes.push_back(Node(9, "X9", 220, 120, 300));
	nodes.push_back(Node(10, "X10", 220, 130, 300));

	Problem problem = Problem(criteria, depot, nodes);
	problem.generateDistances();
	return problem;
}

Problem createRandomProblem(Criteria criteria, ProblemGenParams p) {
	Problem problem(criteria, Node(0, "Depot", 0, 0, 0));
	problem.setCriteria(criteria);
	srand(time(NULL));
	for (uint16_t i = 1; i < p.nodes; ++i) {
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
