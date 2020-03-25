/*
 * RandomModeExecutor.h
 *
 *  Created on: 03 Mar 2020
 *      Author: lubiedak
 */

#include "RandomModeExecutor.h"
#include "RandomProblemGenerator.h"
#include "../solver/CycleCreator.h"
#include "../solver/CycleConnector.h"
#include "io/FileUtils.h"

#include <ctime>
#include <iostream>


std::map<std::string, std::string> RandomModeExecutor::generateAndSolveRandomProblems(int n) {
  std::string dir = prepareExecutionDirectoryName();
  std::map<std::string, std::string> solutions;
  for (int i = 0; i < n; ++i) {
    dir += std::to_string(i) + "/";
    std::string mkdir_command = "mkdir -p " + dir;
    std::cout<<mkdir_command<<std::endl;
#if defined(_WIN32)
	_mkdir(dir.c_str());
#else
	system(mkdir_command.c_str());
#endif
    std::cout<<"Case: "<<i<<std::endl;
    Problem p = createProblem(dir, "ProblemGenParamsCfg");
    Solution s = solveProblem(dir, p);
    solutions[p.toString()] = s.toString();
  }
  return solutions;
}

Problem RandomModeExecutor::createProblem(std::string dir, std::string rndFile){
  ProblemGenParams params = initFromFile(rndFile);
  Criteria c(1000, 1000, 5, 300, 0, 1);

  RandomProblemGenerator rpg(params, c);
  Problem p = rpg.generate();
  FileUtils fileUtils;
  fileUtils.saveToFile(dir + "/input", p.toString());
  p.adapt();
  return p;
}

Solution RandomModeExecutor::solveProblem(std::string dir, Problem p) {
  CycleCreator cc(p);
  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  FileUtils fileUtils;
  fileUtils.saveToFile(dir + "/output", solution.toString());

  std::cout << solution.toString() << std::endl;
  return solution;
}

std::string RandomModeExecutor::prepareExecutionDirectoryName(){
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%d-%m-%Y", timeinfo);
  return "sim" + std::string(buffer) + "/";
}