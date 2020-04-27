/*
 * CycleConnector.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleConnector.h"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <utility>

#include "ProgressLogger.h"

CycleConnector::CycleConnector(const Problem& problem, const std::vector<Cycle>& cycles) :
    problem(problem), cycles(cycles) {
  prepareData();
}

CycleConnector::~CycleConnector() {
  connections.clear();
  baseCycles.clear();
}

void CycleConnector::connect() {
  uint16_t connIteration = 0;
  while (!fullyConnected() && connIteration < 20) {
    connIteration++;
    connectMap(connIteration);
    std::cout << "\niteration: " << connIteration << " connected: " << connections.size() << std::endl;
  }
  bool lastIteration = true;
  auto bestCycleSet = connections[allNodesConnected];
  connIteration++;
  connectMap(connIteration, lastIteration);
  std::cout << "\niteration: " << connIteration << " connected: " << connections.size() << std::endl;

  if(connections[allNodesConnected].distance < bestCycleSet.distance){
    std::cout << "XXXX Connector: improved in last iteration: "<< bestCycleSet.distance << " vs "<< connections[allNodesConnected].distance <<std::endl;
    bestCycleSet = connections[allNodesConnected];

  }
  solution = Solution(bestCycleSet, cycles);
}

void CycleConnector::prepareData() {
  uint16_t biggestDemanderId = problem.getBiggestDemander();

  for (uint16_t i = 0; i < cycles.size(); ++i) {
    if (cycles[i].contains(biggestDemanderId)) {
      connections[cycles[i].getId()] = CyclesSet(cycles[i], i, 1);
    } else {
      baseCycles.push_back(CyclesSet(cycles[i], i, 1));
    }
  }
  allNodesConnected = uint32_t(pow(2.0, problem.size()) - 1);
}


void CycleConnector::connectMap(uint16_t it, bool lastIteration) {
  std::unordered_map<uint32_t, CyclesSet> newConnected = connections;
  connections.clear();
  ProgressLogger progressLogger(newConnected.size(), 20);
  progressLogger.startLog();
  uint32_t i = 0;
  auto endIt = connections.end();
  for (auto conn : newConnected) {
    progressLogger.logProgress(++i);
    uint32_t id1 = conn.second.id;
    for (uint16_t j = conn.second.lastIt; j < baseCycles.size(); ++j) {
      if (0 == (id1 & baseCycles[j].id)) {
        uint32_t id = (id1 | baseCycles[j].id);
        uint16_t distance = baseCycles[j].distance + conn.second.distance;
        if(lastIteration){
          if(id == allNodesConnected){ //last iteration only operates, when allNodesConnected
            if (connections.find(id) == endIt) {
              addCyclesSetToMap(conn.second, baseCycles[j], distance, id, it, j);
            } else if (connections.at(id).distance > distance) {
              addCyclesSetToMap(conn.second, baseCycles[j], distance, id, it, j);
            }
          }
        }
        else {
          // Normal iteration - not the last one
          if (connections.find(id) == endIt) {
            addCyclesSetToMap(conn.second, baseCycles[j], distance, id, it, j);
          } else if (connections.at(id).distance > distance) {
            addCyclesSetToMap(conn.second, baseCycles[j], distance, id, it, j);
          }
        }
      }
    }
  }
}


void CycleConnector::addCyclesSetToMap(CyclesSet& actualCycleSet, CyclesSet& baseCycle, uint16_t distance, uint32_t id,
    uint16_t it, uint16_t lastIt) {

  CyclesSet cycleSet = CyclesSet(id, distance, it + 1, lastIt);
  for (int k = 0; k < it + 1; k++) {
    cycleSet.cycles[k] = actualCycleSet.cycles[k];
  }
  cycleSet.cycles[it] = baseCycle.cycles[0];
  connections[id] = cycleSet;
}

bool CycleConnector::fullyConnected() {
  return connections.find(allNodesConnected) != connections.end();
}

