/*
 * ProblemsForTest.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef TEST_RESOURCES_PROBLEMSFORTEST_H_
#define TEST_RESOURCES_PROBLEMSFORTEST_H_

#include <vector>

#include "../../model/Criteria.h"
#include "../../model/Node.h"
#include "../../model/Problem.h"

Problem problem1() {

	Criteria criteria = Criteria(1000, 20000, 5);

	std::vector<Node> nodes = std::vector<Node>();
	nodes.push_back(Node(0,"Depot",0,0,0 ));
	nodes.push_back(Node(1,"X1",0,0,0 ));

	Problem problem = Problem();

}

#endif /* TEST_RESOURCES_PROBLEMSFORTEST_H_ */
