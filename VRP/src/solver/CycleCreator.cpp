/*
 * CycleCreator.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleCreator.h"

#include <cmath>
#include <iostream>
#include <algorithm>

CycleCreator::CycleCreator(const Problem& p) :
    problem(p) {
  permGen = PermutationGen<int>(problem.getMaxNodes());
  permGen.Permute(problem.getMaxNodes(), problem.getMaxNodes());
  silentMode = false;
  optimizations = false;
}

CycleCreator::CycleCreator(const Problem& p, bool optimize) : CycleCreator(p){
  optimizations = optimize;
}

CycleCreator::~CycleCreator() {
  // TODO Auto-generated destructor stub
}

void CycleCreator::create() {
  /**
   * cycleId is binary representation of cycle from vector of cycles
   * 5 ==> 101 ==> Node_0 and Node_2
   */
  std::vector<uint32_t> cycleIds = countPossibleCycles();
  cycles = std::vector<Cycle>(cycleIds.size());
  std::vector<std::vector<int>> perms = permGen.getFullPermTable();

  for (uint16_t i = 0; i < cycleIds.size(); ++i) {
    cycles[i] = Cycle(cycleIds[i], SumDemand(cycleIds[i], 
      problem.getNodes()), problem.getNodesAndDepot(cycleIds[i]));

    cycles[i].selfOptimize(problem.getDistances(), perms);
  }
  analyzeCycles();
  optimize();
  std::cout<<"XXXXCycleCreator: "<<cycles.size()<<std::endl;
}

std::vector<uint32_t> CycleCreator::countPossibleCycles() {
  uint32_t N = countN();

  std::vector<uint32_t> cycleIds(0);
  cycleIds.reserve(problem.approxCyclesCount());
  uint16_t cycleSize = 0, cargo = 0;

  for (uint32_t id = 1; id <= N; ++id) {
    cycleSize = NumberOfSetBits(id);
    if (cycleSize >= problem.getMinNodes() && cycleSize <= problem.getMaxNodes()) {
      cargo = SumDemand(id, problem.getNodes());
      if (cargo >= problem.getMinCapacity() && cargo <= problem.getMaxCapacity()) {
        cycleIds.push_back(id);
      }
    }
  }
  return cycleIds;
}

unsigned CycleCreator::countN() {
  return (unsigned) (pow(2.0, problem.size()) - pow(2.0, problem.size() - problem.getMaxNodes()));
}

uint32_t CycleCreator::NumberOfSetBits(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

uint16_t CycleCreator::SumDemand(uint32_t set, const std::vector<Node>& nodes) {
  uint16_t cargo = 0;
  for (uint16_t j = 0; j < nodes.size(); ++j) {
    cargo += (set & 1) * nodes[j].getDemand();
    set = set >> 1;
    if (!set)
      break;
  }
  return cargo;
}

bool compareByDemandDistanceRatio(const Cycle& c1, const Cycle& c2){
  return c1.getDemandToDistRatio() < c2.getDemandToDistRatio();
}

bool compareByDemand(const Cycle& c1, const Cycle& c2){
  return c1.getDemand() < c2.getDemand();
}

void CycleCreator::analyzeCycles(){
  //Sort by DemandToDistance ratio
  //TODO does it work?
  std::sort(cycles.begin(), cycles.end(), compareByDemandDistanceRatio);
  int size = cycles.size();
  for(int i = 0; i < size; ++i){
    cycles[i].setDemandToDistRatioRank(i, size);
  }

  //Sort by Demand ratio
  std::sort(cycles.begin(), cycles.end(), compareByDemand);
  for(int i = 0; i < size; ++i){
    cycles[i].setDemandRank(i, size);
  }

  //Sort by distance
  std::sort(cycles.begin(), cycles.end());
  for(int i = 0; i < size; ++i){
    cycles[i].setDistanceRank(i, size);
  }
}

void CycleCreator::optimize(){
  if(optimizations){
    removeFarSingleNodeCycles();
    removeFarAndLowOnDemandDoubleNodesCycles();
  }
}

void CycleCreator::removeFarSingleNodeCycles(){
  int size = cycles.size();
  std::vector<Cycle> singleNodeCycles;
  int maxSize = 0;
  for(int i = 0; i < size; ++i){
    if(cycles[i].size() == 2){
      singleNodeCycles.push_back(cycles[i]);
    }
    if(cycles[i].size()>maxSize){
      maxSize=cycles[i].size();
    }
  }
  //We don't want to remove top closest single node cycles
  singleNodeCycles.erase(singleNodeCycles.begin(), singleNodeCycles.begin() + maxSize-1);
  
  for(auto c: singleNodeCycles){
    removeSafe(c.getId());
  }  
}

void CycleCreator::removeFarAndLowOnDemandDoubleNodesCycles(){
  int size = cycles.size();
  std::vector<Cycle> cyclesToRemove;
  for(int i = 0; i < size; ++i){
    if(cycles[i].size() == 3 
    && cycles[i].getDemandRank() <= 0.6 
    && cycles[i].getDistanceRank() > 0.55){
      cyclesToRemove.push_back(cycles[i]);
    }
  }
  for(auto c: cyclesToRemove){
    removeSafe(c.getId());
  }  
}

void CycleCreator::removeSafe(uint32_t id){
  int sum = 0;
  for(auto c : cycles){
    c.getId() && id ? sum++: sum;
  }
  if(sum>1){
    auto toRemove = std::find_if(std::begin(cycles), std::end(cycles),
            [&](Cycle& c) { return (c.getId() == id); });
    cycles.erase(toRemove);
  }
}

// Remove 2 low on demand and far from depot

