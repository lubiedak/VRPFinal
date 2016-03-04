//============================================================================
// Name        : VRPCore.cpp
// Author      : lubiedak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "io/ArgParser.h"
#include "io/optionparser.h"
#include "io/ProblemLoader.h"
#include "model/Criteria.h"
#include "model/Cycle.h"
#include "solver/CycleConnector.h"
#include "solver/CycleCreator.h"
#include "test/RandomProblemGenerator.h"
#include "test/Tester.h"

void randomProblem(std::string dir, std::string rndFile);
void generateAndSolveRandomProblems(int n);
std::string header(const std::string& title);
void simpleSolve(std::string outputDir, const Problem& p);
void saveSolution(const std::string& dir,Solution& solution);

int main(int argc, char** argv) {
  ArgParser argParser(argc, argv);
  if (argParser.parse()) {
    option::Option* options = argParser.getOptions();
    if (options[TEST].arg) {
      std::cout << header("TEST");
      Tester tester(true);
      tester.runAll();
    }
    if (options[RANDOM].arg) {
      std::cout << options[RANDOM].arg;
      int n = std::stoi(options[RANDOM].arg);
      std::cout << header("RANDOM");
      generateAndSolveRandomProblems(n);
    }
    if (options[INPUT].arg) {
      std::string outDir = "";
      if (options[OUTPUT].arg) {
        std::cout << header("INPUT/OUTPUT");
        outDir = options[OUTPUT].arg;
      }else{
        std::cout << header("INPUT");
      }
      ProblemLoader p(options[INPUT].arg);
      Problem problem = p.load();
      problem.analyze();
      std::cout << problem.toString();

      simpleSolve(outDir, problem);
    }
  }
  return 0;
}

std::string header(const std::string& title) {
  std::string h = "*****************************************\n";
  h += "    " + title + " MODE\n";
  h += "*****************************************\n";
  return h;
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
    std::cout<<"Case: "<<i<<std::endl;
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
  saveSolution(dir, solution);

  std::cout << solution.toString() << std::endl;
}

void simpleSolve(std::string outputDir, const Problem& p) {
  CycleCreator cc(p);
  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  std::cout << solution.toString() << std::endl;
  saveSolution(outputDir, solution);
}

void saveSolution(const std::string& dir,Solution& solution){
  std::ofstream myfile;
  myfile.open((dir + "output").c_str());
  myfile << solution.toString();
  myfile.close();
}
