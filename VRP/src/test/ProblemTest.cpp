/*
 * ProblemTest.cpp
 *
 *  Created on: 9 Jan 2016
 *      Author: lubiedak
 */

#include "ProblemTest.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <time.h>

#include "../solver/CycleConnector.h"
#include "../solver/CycleCreator.h"
#include "../solver/CyclesSet.h"
#include "../solver/Solution.h"
#include "resources/ProblemsForTest.h"
#include "../random/RandomProblemGenerator.h"
#include "../random/RandomModeExecutor.h"
#include "../io/DistanceMatrix.h"

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

bool ProblemTemplate_TEST(Problem p, uint32_t expectedCycles, uint32_t expectedDemand,
    uint32_t expectedDistance) {
  CycleCreator cc(p);

  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  return expectedCycles == cycles.size() && solution.getDemand() == expectedDemand
      && solution.getDistance() == expectedDistance;
}

bool DistancesCreation_TEST() {
  std::vector<Node> nodes = std::vector<Node>();
  nodes.push_back(Node(0, "", 0, 0, 100));
  nodes.push_back(Node(0, "", 3, 4, 100));
  
  Problem p = Problem(Criteria(1000, 100, 0), Node(), nodes);
  std::vector<std::vector<unsigned short>> dist = p.getDistances();
  return dist[1][2] == 5;
}

bool RandomProblem_TEST() {
  ProblemGenParams params;
  params.maxDemand = 500;
  params.minDemand = 100;
  params.maxX = 1000;
  params.maxY = 1000;
  params.nodes = 20;

  Criteria c(1000, 1000, 5, 300, 0, 1);

  RandomProblemGenerator rpg(params, c);

  Problem p = rpg.generate();
  p.adapt();
  std::cout << p.toString();
  CycleCreator cc(p);

  cc.create();
  std::vector<Cycle> cycles = cc.getCycles();

  CycleConnector ccon(p, cycles);
  ccon.connect();

  Solution solution = ccon.getSolution();

  return true;
}

bool Problem5Nodes_TEST() {
  Problem p = problem5Nodes();

  return ProblemTemplate_TEST(p, 25, 1501, 537);
}

bool Problem6Nodes_TEST() {
  Problem p = problem6Nodes();

  return ProblemTemplate_TEST(p, 56, 1320, 602);
}

bool Problem10Nodes_TEST() {
  Problem p = problem10Nodes();
  return ProblemTemplate_TEST(p, 175, 3001, 1943);
}

bool Problem20Nodes_TEST() {
  Problem p = problem20Nodes();
  return ProblemTemplate_TEST(p,20349, 3982, 2844);
}

bool DistanceMatrixReading_TEST(){
  DistanceMatrix distanceMatrix;
  distanceMatrix.readFromFile("../../web/miasta/odleglosci.csv");
  return true;
}

bool ZPerformance_TEST() {
  RandomModeExecutor executor;
  Problem lastProblem;
  Solution lastSolution;
  ProblemGenParams params = initFromFile("/Users/lukasz.biedak/workspace/VRPFinal/VRP/build/ProblemGenParamsCfg");
  int allOperations=0;
  int optimizationIsWorse = 0;
  for(int x = 0; x<100; x++){
    std::cout<<"XXXX "<<x<<std::endl;
    params.nodes = 22;
    auto problem = executor.createProblem("rest", params);
    //problem = setDemandsTo(problem, 250);
    
    for(int i = 0; i<4; i++){
      allOperations++;
      std::cout<<"                                 XXXX "<<x<<std::endl;
      clock_t tStart = clock();
      Solution solution = executor.solveProblem("rest", problem);
      double time = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      std::cout<<"XXXX;"<<problem.size()<<";"<<solution.getDemand()<<";"
        <<solution.getDistance()<<";"<<time<<std::endl;

      tStart = clock();
      Solution solutionOptimized = executor.solveProblem("rest", problem, true);
      time = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      std::cout<<"XXXX;"<<problem.size()<<";"<<solutionOptimized.getDemand()<<";"
        <<solutionOptimized.getDistance()<<";"<<time<<std::endl;
      
      if(solution.getDistance() < solutionOptimized.getDistance()){
        optimizationIsWorse++;
        std::cout<<"                                                                  XXXXXX;"<<problem.size()<<";"<<solution.getDistance()<<";"
        <<solutionOptimized.getDistance()<<";"<<optimizationIsWorse<<";"<<allOperations<<std::endl;
      }
      if(allOperations%50==0){
        std::cout<<"                                                                  XXXXXX;"<<allOperations<<std::endl;
      }
      problem.removeLastNode();
    }
  }
  return true;
}

bool ZAnalyze_TEST() {
  RandomModeExecutor executor;
  Problem lastProblem;
  Solution lastSolution;
  for(int x = 0; x<100; ++x){
    lastSolution.setDistance(0);
    std::cout<<"XXXX"<<x<<std::endl;
    auto problem = executor.createProblem("rest", "ProblemGenParamsCfg");
    problem = decreaseDemandToRoundDemand(problem);
    for(size_t i = 0 ; i<1000/problem.getNodes().size(); ++i){
      Solution solution = executor.solveProblem("rest", problem);
      std::cout<<"XXXX;"<<i<<";"<<solution.getDemand()<<";"<<solution.getDistance()
      <<";"<<solution.getSize()<<std::endl;
      if(lastSolution.getDistance() > solution.getDistance() ){
        std::cout << lastProblem.toString() << std::endl;
        std::cout << problem.toString() << std::endl;
        std::cout << lastSolution.toString() << std::endl;
        std::cout << solution.toString() << std::endl;
      }
      lastProblem = problem;
      lastSolution = solution;
      problem = increaseDemandsByOne(problem);
    }
  }
  return true;
}

Problem decreaseDemandToRoundDemand(Problem problem){
  int totalDemand = problem.getDemandsSum();
  int reduction = (totalDemand - (totalDemand/1000)*1000)/problem.getNodes().size();
  std::vector<Node> nodes;
  for(Node node: problem.getNodes()){
    Node newNode = node;
    newNode.setDemand(node.getDemand() - reduction);
    nodes.push_back(newNode);
  }
  problem.setNodes(nodes);
  problem.adapt();
  return problem;
}

Problem increaseDemandsByOne(Problem problem){
  std::vector<Node> nodes;
  for(Node node: problem.getNodes()){
    Node newNode = node;
    newNode.setDemand(node.getDemand() + 1);
    nodes.push_back(newNode);
  }
  problem.setNodes(nodes);
  problem.adapt();
  return problem;
}

Problem setDemandsTo(Problem problem, int demand){
  std::vector<Node> nodes;
  for(Node node: problem.getNodes()){
    Node newNode = node;
    newNode.setDemand(demand);
    nodes.push_back(newNode);
  }
  problem.setNodes(nodes);
  problem.adapt();
  return problem;
}

