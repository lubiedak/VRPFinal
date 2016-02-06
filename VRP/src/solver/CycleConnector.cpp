/*
 * CycleConnector.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleConnector.h"
#include <cmath>
#include <iostream>

CycleConnector::CycleConnector(const Problem& problem, const std::vector<Cycle>& cycles) :
    problem(problem), cycles(cycles) {
  prepareData();
}

CycleConnector::~CycleConnector() {
  // TODO Auto-generated destructor stub
  for (auto it : connections) {
    delete it.second;
  }
  for (auto it : baseCycles) {
    delete it;
  }
  for (auto it : specialCycles) {
    delete it;
  }
  connections.clear();
  baseCycles.clear();
  specialCycles.clear();
}

void CycleConnector::connect() {
  uint16_t connIteration = 1;
  connectMap(connIteration);
  std::cout << "iteration: " << connIteration << " connected: " << connections.size() << std::endl;

  while (!fullyConnected()) {
    connIteration++;
    connectMap(connIteration);
    std::cout << "iteration: " << connIteration << " connected: " << connections.size() << std::endl;
  }
  solution = Solution(*connections[allNodesConnected], cycles);
}

void CycleConnector::prepareData() {
  uint16_t biggestDemanderId = problem.getBiggestDemander();

  for (uint16_t i = 0; i < cycles.size(); ++i) {
    if (cycles[i].contains(biggestDemanderId)) {
      specialCycles.push_back(new CyclesSet(cycles[i], i, 1));
      connections[cycles[i].getId()] = new CyclesSet(cycles[i], i, 1);
    } else {
      baseCycles.push_back(new CyclesSet(cycles[i], i, 1));
    }
  }
  allNodesConnected = uint32_t(pow(2.0, problem.size()) - 1);
}

void CycleConnector::connectMap(uint16_t it) {

  std::map<uint32_t, CyclesSet*> newConnected = connections;
  uint32_t size = newConnected.size();
  uint32_t step = size / 4;
  uint32_t i = 0;

  bool foundFirstFull = false;

  for (auto conn : newConnected) {
    ++i;
    uint32_t id1 = conn.second->id;
    for (uint16_t j = 0; j < baseCycles.size(); ++j) {
      //IF They don't have common Node

      if (0 == (id1 & baseCycles[j]->id)) {
        if (i > step) {
          //std::cout<<i<<" from "<<size<<" analyzed."<<std::endl;
          step += step;
        }
        uint32_t id = (id1 | baseCycles[j]->id);
        if (!foundFirstFull) {

          uint16_t distance = baseCycles[j]->distance + conn.second->distance;

          if (connections.find(id) == connections.end()) {

            addCyclesSetToMap(*conn.second, *baseCycles[j], distance, id, it);
            if (id == allNodesConnected) {
              std::cout << "NE: " << connections.at(id)->toString() << std::endl;
              foundFirstFull = true;
            }

          } else if (connections.at(id)->distance > distance) {

            addCyclesSetToMap(*conn.second, *baseCycles[j], distance, id, it);
            if (id == allNodesConnected)
              std::cout << "DE: " << connections.at(id)->toString() << std::endl;
          }
        } else {
          if (id == allNodesConnected) {
            uint16_t distance = baseCycles[j]->distance + conn.second->distance;
            if (connections.at(id)->distance > distance) {

              addCyclesSetToMap(*conn.second, *baseCycles[j], distance, id, it);
              std::cout << "DE2: " << connections.at(id)->toString() << std::endl;
            }
          }
        }
      }
    }
  }
}

void CycleConnector::addCyclesSetToMap(CyclesSet& actualCycleSet, CyclesSet& baseCycle, uint16_t distance, uint32_t id,
    uint16_t it) {

  CyclesSet* cycleSet = new CyclesSet(id, distance, it + 1);
  for (int k = 0; k < it + 1; k++) {
    cycleSet->cycles[k] = actualCycleSet.cycles[k];
  }

  cycleSet->cycles[it] = baseCycle.cycles[0];
  delete connections[id];
  connections[id] = cycleSet;
}

bool CycleConnector::fullyConnected() {
  return connections.find(allNodesConnected) != connections.end();
}

