//============================================================================
// Name        : VRPCore.cpp
// Author      : lubiedak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "io/ArgParser.h"
#include "io/ProblemLoader.h"
#include "model/Criteria.h"
#include "model/Cycle.h"
#include "solver/CycleConnector.h"
#include "solver/CycleCreator.h"
#include "test/RandomProblemGenerator.h"

void randomProblem(std::string dir, std::string rndFile);
void generateAndSolveRandomProblems(int n);

int main(int argc, char** argv) {
  ArgParser argParser(argc, argv);

  generateAndSolveRandomProblems(2);

  ProblemLoader p("../src/test/resources/problemExample.txt");
  Problem problem = p.load();
  std::cout << problem.toString();
  return 0;
}

void generateAndSolveRandomProblems(int n) {
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
    std::string mkdir = "mkdir -p " + dir;
    system(mkdir.c_str());
    randomProblem(dir, "ProblemGenParamsCfg");

  }
}

void randomProblem(std::string dir, std::string rndFile) {
  ProblemGenParams params = initFromFile(rndFile);
  Criteria c(1000, 1000, 5, 300, 0, 1);

  RandomProblemGenerator rpg(params, c);

  Problem p = rpg.generate();
  rpg.save(dir, "input");
  p.analyze();
  p.toString();
  CycleCreator cc(p);

  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  std::ofstream myfile;
  myfile.open((dir + "output").c_str());
  myfile << solution.toString();
  myfile.close();

  std::cout << solution.toString() << std::endl;
}
