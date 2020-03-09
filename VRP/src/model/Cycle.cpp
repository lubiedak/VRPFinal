/*
 * Cycle.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Cycle.h"

#include <cstdint>
#include <sstream>

#include "../solver/PermutationGen.h"

const uint32_t permBorders[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };

Cycle::Cycle() :
    id(0), distance(0), demand(0), capacity(0), distCoef(0.0) {
  nodes = std::vector<Node>();
  membersCount = 6;

  this->demandRank = 0.0;
  this->demandToDistRatio = 0.0;
  this->demandToDistRatioRank = 0.0;
  this->distanceRank = 0.0;
}

Cycle& Cycle::operator =(const Cycle& c) {
  this->id = c.id;
  this->capacity = c.capacity;
  this->demand = c.demand;
  this->distance = c.distance;
  this->nodes = c.nodes;
  this->membersCount = c.membersCount;
  this->distCoef = c.distCoef;

  this->demandRank = c.demandRank;
  this->demandToDistRatio = c.demandToDistRatio;
  this->demandToDistRatioRank = c.demandToDistRatioRank;
  this->distanceRank = c.distanceRank;

  return *this;
}

Cycle::Cycle(const Cycle& c) {
  id = c.id;
  distance = c.distance;
  demand = c.demand;
  capacity = c.capacity;
  nodes = c.nodes;
  membersCount = c.membersCount;
  distCoef = c.distCoef;

  demandRank = c.demandRank;
  demandToDistRatio = c.demandToDistRatio;
  demandToDistRatioRank = c.demandToDistRatioRank;
  distanceRank = c.distanceRank;
}

Cycle::~Cycle() {
  // TODO Auto-generated destructor stub
}

std::string Cycle::toString() {
  std::stringstream oss;
  oss << std::string("class=Cycle");
  oss << delimiter << "id" << pairDelimiter << id;
  oss << delimiter << "distance" << pairDelimiter << distance;
  oss << delimiter << "distCoef" << pairDelimiter << distCoef;
  oss << delimiter << "distanceRank" << pairDelimiter << distanceRank;
  oss << delimiter << "demand" << pairDelimiter << demand;
  oss << delimiter << "demandToDistRatio" << pairDelimiter << demandToDistRatio;
  oss << delimiter << "demandToDistRatioRank" << pairDelimiter << demandToDistRatioRank;
  oss << delimiter << "demandRank" << pairDelimiter << demandRank;
  // TODO
  //oss << delimiter << "capacity" << mapDelimiter << capacity;
  int i = 0;
  for (auto n : nodes) {
    oss << delimiter << "nodeId" << i++ << pairDelimiter << n.getId();
  }

  return oss.str();
}

crow::json::wvalue Cycle::toJson(){
  crow::json::wvalue json;
  json["id"] = id;
  json["distance"] = distance;
  json["distCoef"] = distCoef;
  json["distanceRank"] = distanceRank;
  json["demand"] = demand;
  json["demandToDistRatio"] = demandToDistRatio;
  json["demandToDistRatioRank"] = demandToDistRatioRank;
  json["demandRank"] = demandRank;
  int i = 0;
  for (auto n : nodes) {
    json["nodes"][i++] = n.getId();
  }
  return json;
}

std::vector<Edge> Cycle::toEdges(){
  std::vector<Edge> edges;
  std::string id_str = std::to_string(id) + "_";
  for (int i=1; i<nodes.size(); ++i) {
    std::string name = id_str + std::to_string(nodes[i-1].getId()) + "_" + std::to_string(nodes[i].getId());
    edges.push_back(Edge(name, nodes[i-1].getId(), nodes[i].getId()));
  }
  std::string name = id_str + "_" + std::to_string(nodes[nodes.size()-1].getId()) + "_" + std::to_string(nodes[0].getId());
  edges.push_back(Edge(name, nodes[nodes.size()-1].getId(), nodes[0].getId()));
  return edges;
}


std::string Cycle::serialize() {
  return toString();
}

bool Cycle::deserialize(std::string allocator) {
  return true;
}

uint16_t Cycle::selfOptimize(const std::vector<std::vector<uint16_t> >& distances,
    std::vector<std::vector<int> >& perms) {

  if (nodes.size() - 1 == 0)
    return 0;
  checkPermSize(perms);
  distance = countMinimumDistance(distances, perms);
  demandToDistRatio = 100.0*demand/distance;

  return distance;
}

void Cycle::checkPermSize(std::vector<std::vector<int>>& perms) {
  uint16_t size = nodes.size() - 1;
  if (size > perms[0].size()) {
    PermutationGen<int> permGen(size);
    perms = permGen.getFullPermTable();
  }
}

bool Cycle::operator <(const Cycle& c) const {
  return distance < c.distance;
}

uint16_t Cycle::countMinimumDistance(const std::vector<std::vector<uint16_t> >& distances,
    const std::vector<std::vector<int> >& perms) {
  uint16_t size = nodes.size() - 1;
  uint16_t minDistance = 20000;
  uint16_t bestPerm = 0;
  uint16_t dist = 0;
  uint16_t depotId = nodes[0].getId();
  uint16_t first = 0;
  uint16_t last = 0;

  for (uint32_t i = 0; i < permBorders[size]; ++i) {
    first = nodes[1 + perms[i][0]].getId();
    last = nodes[1 + perms[i][size - 1]].getId();

    dist = distances[depotId][first];
    dist += distances[last][depotId];
    distCoef = 0.0;

    for (int j = 1; j < size; ++j) {

      dist += distances[nodes[1 + perms[i][j - 1]].getId()][nodes[1 + perms[i][j]].getId()];
      distCoef += distances[nodes[1 + perms[i][j - 1]].getId()][nodes[1 + perms[i][j]].getId()];
    }
    if (dist < minDistance) {
      minDistance = dist;
      bestPerm = i;
    }
  }

  // change nodes order
  std::vector<Node> nodesCopy = nodes;
  for (uint16_t i = 1; i <= size; i++) {
    nodes[i] = nodesCopy[perms[bestPerm][i - 1] + 1];
  }
  distCoef = 100 * distCoef / dist;

  return minDistance;
}

bool Cycle::contains(uint16_t nodeId) const {
  for (Node n : nodes) {
    if (nodeId == n.getId())
      return true;
  }
  return false;
}
