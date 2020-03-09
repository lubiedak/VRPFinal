/*
 * Solution.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Solution.h"

Solution::Solution(CyclesSet& cs, const std::vector<Cycle>& cycles) :
    Serialized() {
  demand = 0;
  for (uint16_t i = 0; i < cs.cycles.size(); ++i) {
    optimizedCycles.push_back(cycles[cs.cycles[i]]);
    demand += cycles[cs.cycles[i]].getDemand();
  }
  distance = cs.distance;
}

Solution::~Solution() {
  // TODO Auto-generated destructor stub
}

std::string Solution::serialize() {
  std::stringstream oss;
  oss << std::string("class=Solution");
  oss << delimiter << "distance" << pairDelimiter << distance;
  oss << delimiter << "demand" << pairDelimiter << demand << std::endl;
  for (auto c : optimizedCycles) {
    oss << c.toString() << std::endl;
  }
  return oss.str();
}

bool Solution::deserialize(std::string allocator) {
  return true;
}

std::string Solution::toString() {
  return serialize();
}

crow::json::wvalue Solution::toJson(){
  crow::json::wvalue json;
  json["distance"] = distance;
  json["demand"] = demand;
  int i = 0;
  for (auto c : optimizedCycles) {
    json["cycles"][i++] =c.toJson();
  }
  return json;
}

crow::json::wvalue Solution::toJsonForDrawing(){
  crow::json::wvalue json;
  int i = 0;
  for (auto c : optimizedCycles) {
    for (auto e : c.toEdges()){
      json["edges"][i++] = e.toJsonForDrawing();
    }
  }
  return json;
}
