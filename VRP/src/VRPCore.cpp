//============================================================================
// Name        : VRPCore.cpp
// Author      : lubiedak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#if defined(_WIN32)
#include <direct.h>
#endif 

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include "io/ArgParser.h"
#include "io/optionparser.h"
#include "io/ApiController.h"
#include "io/ProblemLoader.h"
#include "io/FileUtils.h"
#include "model/Criteria.h"
#include "model/Cycle.h"
#include "solver/CycleConnector.h"
#include "solver/CycleCreator.h"
#include "random/RandomModeExecutor.h"
#include "test/Tester.h"

std::string header(const std::string& title);
void simpleSolve(std::string outputDir, const Problem& p);

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
      int n = std::stoi(options[RANDOM].arg);
      std::cout << header("RANDOM");
      
      RandomModeExecutor randomModeExecutor;
      randomModeExecutor.generateAndSolveRandomProblems(n);
    }
    if (options[MICRO].arg) {
      std::cout << header("MICRO");
      
      ApiController api;
      api.run();
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
      problem.adapt();
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

void simpleSolve(std::string outputDir, const Problem& p) {
  CycleCreator cc(p);
  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  std::cout << solution.toString() << std::endl;
  FileUtils FileUtils;
  FileUtils.saveToFile(outputDir, solution.toString());
}
