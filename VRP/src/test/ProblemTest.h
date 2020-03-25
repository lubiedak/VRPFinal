/*
 * ProblemTest.h
 *
 *  Created on: 18 Dec 2015
 *      Author: lubiedak
 */

#ifndef TEST_PROBLEMTEST_H_
#define TEST_PROBLEMTEST_H_

#include "../model/Problem.h"

bool DistancesCreation_TEST(bool silentMode);
bool RandomProblem_TEST(bool silentMode);
bool Problem5Nodes_TEST(bool silentMode);
bool Problem6Nodes_TEST(bool silentMode);
bool Problem10Nodes_TEST(bool silentMode);
bool Problem20Nodes_TEST(bool silentMode);
bool ZAnalyze_TEST(bool silentMode);
int countDemand(Problem problem);
Problem decreaseDemandToRoundDemand(Problem problem);
Problem increaseDemandsByOne(Problem problem);

#endif /* TEST_PROBLEMTEST_H_ */
