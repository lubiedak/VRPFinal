/*
 * RandomModeExecutor.h
 *
 *  Created on: 03 Mar 2020
 *      Author: lubiedak
 */

#ifndef RANDOM_RANDOM_MODE_EXECUTOR_H_
#define RANDOM_RANDOM_MODE_EXECUTOR_H_

#include <string>
#include "../solver/Solution.h"
#include "../model/Problem.h"
#include "RandomProblemGenerator.h"

class RandomModeExecutor {
public:
    RandomModeExecutor(void){};
    std::map<std::string, std::string> generateAndSolveRandomProblems(int n);
    Problem createProblem(std::string dir, std::string rndFile);
    Problem createProblem(std::string dir, ProblemGenParams params);
    Solution solveProblem(std::string dir, Problem p, bool optimize=false);
    Solution solveProblemForCities(std::string dir, Problem p);
private:
    std::string prepareExecutionDirectoryName();

};
#endif /* RANDOM_RANDOM_MODE_EXECUTOR_H_ */
