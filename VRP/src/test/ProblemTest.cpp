/*
 * ProblemTest.cpp
 *
 *  Created on: 9 Jan 2016
 *      Author: lubiedak
 */

#include "../model/Problem.h"
#include "ProblemTest.h"

#include <cstdint>
#include <iostream>
#include <string>

#include "../solver/CycleConnector.h"
#include "../solver/CycleCreator.h"
#include "../solver/CyclesSet.h"
#include "../solver/Solution.h"
#include "resources/ProblemsForTest.h"
#include "RandomProblemGenerator.h"

void printCycles(const std::vector<Cycle>& cycles) {
  int i = 0;
  for (Cycle c : cycles) {
    std::cout << i++ << "  " << c.toString() << std::endl;
  }
}

void printConnected(const std::vector<CyclesSet*>& connected) {
  int i = 0;
  for (CyclesSet* c : connected) {
    std::cout << i++ << "  " << c->toString() << std::endl;
  }
}

bool ProblemTemplate_TEST(Problem p, bool silentMode, uint32_t expectedCycles, uint32_t expectedDemand,
    uint32_t expectedDistance) {
  CycleCreator cc(p);

  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  if (!silentMode)
    std::cout << solution.toString() << std::endl;

  return expectedCycles == cycles.size() && solution.getDemand() == expectedDemand
      && solution.getDistance() == expectedDistance;
}

bool DistancesCreation_TEST(bool silentMode) {
  Problem p = Problem(Criteria(0, 0, 0), Node());
  p.addNode(Node(0, "", 0, 0, 0));
  p.addNode(Node(0, "", 3, 4, 0));

  p.generateDistances();
  std::vector<std::vector<unsigned short>> dist = p.getDistances();
  return dist[1][2] == 5;
}

bool RandomProblem_TEST(bool silentMode) {
  ProblemGenParams params;
  params.maxDemand = 500;
  params.minDemand = 100;
  params.maxX = 1000;
  params.maxY = 1000;
  params.nodes = 20;

  Criteria c(1000, 1000, 5, 300, 0, 1);

  RandomProblemGenerator rpg(params, c);

  Problem p = rpg.generate();
  p.analyze();
  std::cout << p.toString();
  CycleCreator cc(p);

  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  if (!silentMode)
    std::cout << solution.toString() << std::endl;

  return true;
}

bool Problem5Nodes_TEST(bool silentMode) {
  Problem p = problem5Nodes();

  return ProblemTemplate_TEST(p, silentMode, 25, 1501, 537);
}

bool Problem6Nodes_TEST(bool silentMode) {
  Problem p = problem6Nodes();

  return ProblemTemplate_TEST(p, silentMode, 56, 1320, 602);
}

bool Problem10Nodes_TEST(bool silentMode) {
  Problem p = problem10Nodes();
  return ProblemTemplate_TEST(p, silentMode, 175, 3001, 1943);
}

bool Problem20Nodes_TEST(bool silentMode) {
  Problem p = problem20Nodes();
  return ProblemTemplate_TEST(p, silentMode, 20349, 3982, 2844);
}

