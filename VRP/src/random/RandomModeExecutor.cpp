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


void RandomModeExecutor::generateAndSolveRandomProblems(int n) {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%d-%m-%Y", timeinfo);
  std::string timed(buffer);

  for (int i = 0; i < n; ++i) {
    std::string dir = "sim";
    dir += timed + "/";
    dir += std::to_string(i);
    dir += "/";
    std::string mkdir_command = "mkdir -p " + dir;
    std::cout<<mkdir_command<<std::endl;
#if defined(_WIN32)
	_mkdir(mkdir_command.c_str());
#endif
#if defined(__APPLE__)
    system(mkdir_command.c_str());
#else
	mkdir(mkdir_command.c_str()); // notice that 777 is different than 0777
#endif
    std::cout<<"Case: "<<i<<std::endl;
    randomProblem(dir, "ProblemGenParamsCfg");
  }
}

void RandomModeExecutor::randomProblem(std::string dir, std::string rndFile) {
  ProblemGenParams params = initFromFile(rndFile);
  Criteria c(1000, 1000, 5, 300, 0, 1);

  RandomProblemGenerator rpg(params, c);
  Problem p = rpg.generate();
  FileUtils fileUtils;
  fileUtils.saveToFile(dir + "input", p.toString());
  p.analyze();
  p.toString();
  CycleCreator cc(p);

  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  fileUtils.saveToFile(dir + "output", solution.toString());

  std::cout << solution.toString() << std::endl;
}