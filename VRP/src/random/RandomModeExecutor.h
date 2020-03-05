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

class RandomModeExecutor {
public:
    RandomModeExecutor(void){};
    void generateAndSolveRandomProblems(int n);
private:
    Problem createProblem(std::string dir, std::string rndFile);
    Solution solveProblem(std::string dir, Problem p);
    std::string prepareExecutionDirectoryName();

};
#endif /* RANDOM_RANDOM_MODE_EXECUTOR_H_ */
