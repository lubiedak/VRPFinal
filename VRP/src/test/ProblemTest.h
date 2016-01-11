/*
 * ProblemTest.h
 *
 *  Created on: 18 Dec 2015
 *      Author: lubiedak
 */

#ifndef TEST_PROBLEMTEST_H_
#define TEST_PROBLEMTEST_H_

#include "../model/Problem.h"

#include <iostream>
#include <string>

#include "../solver/CycleCreator.h"
#include "../solver/CycleConnector.h"
#include "../solver/Solution.h"
#include "resources/ProblemsForTest.h"


bool DistancesCreation_TEST(bool silentMode);
bool RandomProblem_TEST(bool silentMode);
bool Problem5Nodes_TEST(bool silentMode);
bool Problem6Nodes_TEST(bool silentMode);
bool Problem10Nodes_TEST(bool silentMode);
bool Problem20Nodes_TEST(bool silentMode);


#endif /* TEST_PROBLEMTEST_H_ */
