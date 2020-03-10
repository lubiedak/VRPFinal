/*
 * Problem.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Problem.h"
#include <math.h>
#include <iostream>

Problem::Problem(Criteria criteria, Node depot) :
    criteria(criteria), depot(depot) {
  std::cout << "WARNING: Problem creation. Nodes not specified." << std::endl;
}

Problem::Problem(Criteria criteria, Node depot, std::vector<Node> nodes) :
    criteria(criteria), depot(depot), nodes(nodes) {
  std::cout << "WARNING: Problem creation. Distances not specified."
      "Counting defaults" << std::endl;
  generateDistances();
  analyze();
}

Problem::Problem(Criteria criteria, Node depot, std::vector<Node> nodes, std::vector<std::vector<uint16_t> > distances) :
    criteria(criteria), depot(depot), nodes(nodes), distances(distances) {
  analyze();
}

Problem::Problem(Problem& p) :
    criteria(p.criteria), depot(p.depot), nodes(p.nodes), distances(p.distances), cycles(p.cycles) {
  analyze();
}

Problem::Problem(const crow::json::rvalue& json){
  crow::logger logger("problem", crow::LogLevel::INFO);
        logger<<json;
  criteria = Criteria(json["criteria"]);
  analyze();
}

void Problem::analyze() {
  biggestDemander = findBiggestDemander();
  demandsSum = sumDemands();
  generateDistances();
  changeMinDemandIfNeeded();
}

uint16_t Problem::findBiggestDemander() {
  uint16_t bigDemand = 0;
  uint16_t demander = 0;
  for (uint16_t i = 0; i < nodes.size(); ++i) {
    if (nodes[i].getDemand() > bigDemand) {
      bigDemand = nodes[i].getDemand();
      demander = nodes[i].getId();
    }
  }
  return demander;
}

void Problem::generateDistances() {
  std::vector<Node> nodesAndDepot = nodes;
  nodesAndDepot.insert(nodesAndDepot.begin(), depot);
  uint16_t size = nodesAndDepot.size();
  distances = std::vector<std::vector<uint16_t> >(size, std::vector<uint16_t>(size));
  for (unsigned i = 0; i < size; ++i) {
    for (unsigned j = 0; j < size; ++j) {
      int x = nodesAndDepot[i].getX() - nodesAndDepot[j].getX();
      int y = nodesAndDepot[i].getY() - nodesAndDepot[j].getY();
      distances[i][j] = (uint16_t) round(sqrt(0.0f + x * x + y * y));
    }
  }
}

uint16_t Problem::approxCyclesCount() const {
  //TODO - finding better way
  return size() * 30;
}

std::vector<Node> Problem::getNodesAndDepot(uint32_t set) const {
  std::vector<Node> chosenNodes;
  chosenNodes.push_back(depot);
  for (uint16_t j = 0; j < nodes.size(); ++j) {
    if (set & 1)
      chosenNodes.push_back(nodes[j]);
    set = set >> 1;
    if (!set)
      break;
  }
  return chosenNodes;
}

std::string Problem::toString() {
  std::string problem = "class=Problem\n";
  problem += criteria.toString() + "\n";
  problem += depot.toString() + "\n";
  for (Node n : nodes) {
    problem += n.toString() + "\n";
  }
  return problem;
}

crow::json::wvalue Problem::toJson() {
  crow::json::wvalue json;
  int i = 0;
  for (Node n : nodes) {
    json["nodes"][i++] = n.toJson();
  }
  json["depot"] = depot.toJson();
  json["criteria"] = criteria.toJson();

  return json;
}

crow::json::wvalue Problem::toJsonForDrawing() {
  crow::json::wvalue json;
  int i = 0;
  json["nodes"][i++] = depot.toJsonForDrawing();
  for (Node n : nodes) {
    json["nodes"][i++] = n.toJsonForDrawing();
  }

  json["criteria"] = criteria.toJson();

  return json;
}

uint16_t Problem::sumDemands() {
  uint16_t demand = 0;
  for (uint16_t i = 0; i < nodes.size(); ++i) {
    demand += nodes[i].getDemand();
  }
  return demand;
}

uint16_t Problem::estimateConnectionsNeeded() const {
  return demandsSum / criteria.maxCapacity() + 1;
}

//Optimization
void Problem::changeMinDemandIfNeeded() {
  uint16_t minDemand = demandsSum % criteria.maxCapacity();
  if(minDemand < 0.88 * criteria.maxCapacity() && minDemand > criteria.minCapacity()){
    criteria.setMinCapacity(minDemand);
    std::cout<<"MinCapacity changed to "<<minDemand<<std::endl;
  }
}
