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
  specialCycles.clear();
}

void CycleConnector::connect() {
  uint16_t connIteration = 0;

  while (!fullyConnected()) {
    connIteration++;
    connectMap(connIteration);
    std::cout << "\niteration: " << connIteration << " connected: " << connections.size() << std::endl;
  }

  solution = Solution(connections[allNodesConnected], cycles);
}

void CycleConnector::prepareData() {
  uint16_t biggestDemanderId = problem.getBiggestDemander();

  for (uint16_t i = 0; i < cycles.size(); ++i) {
    if (cycles[i].contains(biggestDemanderId)) {
      specialCycles.push_back(CyclesSet(cycles[i], i, 1));
      connections[cycles[i].getId()] = CyclesSet(cycles[i], i, 1);
    } else {
      baseCycles.push_back(CyclesSet(cycles[i], i, 1));
    }
  }
  allNodesConnected = uint32_t(pow(2.0, problem.size()) - 1);
}


void CycleConnector::connectMap(uint16_t it) {
  std::map<uint32_t, CyclesSet> newConnected = connections;
  ProgressLogger progressLogger(newConnected.size(), 20);
  progressLogger.startLog();
  uint32_t i = 0;
  bool foundFirstFull = false;
  auto entIt = connections.end();
  for (auto conn : newConnected) {
    ++i;
    progressLogger.logProgress(i);
    uint32_t id1 = conn.second.id;
    for (uint16_t j = 0; j < baseCycles.size(); ++j) {
      if (0 == (id1 & baseCycles[j].id)) {
        uint32_t id = (id1 | baseCycles[j].id);

        if (!foundFirstFull) {
          uint16_t distance = baseCycles[j].distance + conn.second.distance;
          if (connections.find(id) == entIt) {
            addCyclesSetToMap(conn.second, baseCycles[j], distance, id, it);
            foundFirstFull = (id == allNodesConnected);
          } else if (connections.at(id).distance > distance) {
            addCyclesSetToMap(conn.second, baseCycles[j], distance, id, it);
          }
          //foundFirstFull
        } else {
          if (id == allNodesConnected) {
            uint16_t distance = baseCycles[j].distance + conn.second.distance;
            if (connections.at(id).distance > distance) {
              addCyclesSetToMap(conn.second, baseCycles[j], distance, id, it);
              std::cout<<"B";
            }
          }
        }
      }
    }
  }
}


void CycleConnector::addCyclesSetToMap(CyclesSet& actualCycleSet, CyclesSet& baseCycle, uint16_t distance, uint32_t id,
    uint16_t it) {

  CyclesSet cycleSet = CyclesSet(id, distance, it + 1);
  for (int k = 0; k < it + 1; k++) {
    cycleSet.cycles[k] = actualCycleSet.cycles[k];
  }
  cycleSet.cycles[it] = baseCycle.cycles[0];
  connections[id] = cycleSet;
}

bool CycleConnector::fullyConnected() {
  return connections.find(allNodesConnected) != connections.end();
}

