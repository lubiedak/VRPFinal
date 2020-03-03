/*
 * RandomModeExecutor.h
 *
 *  Created on: 03 Mar 2020
 *      Author: lubiedak
 */

#ifndef RANDOM_RANDOM_MODE_EXECUTOR_H_
#define RANDOM_RANDOM_MODE_EXECUTOR_H_

#include <string>

class RandomModeExecutor {
public:
    RandomModeExecutor(void){};
    void generateAndSolveRandomProblems(int n);
private:
    void randomProblem(std::string dir, std::string rndFile);

};
#endif /* RANDOM_RANDOM_MODE_EXECUTOR_H_ */
