/*
 * RandomProblemGenerator.cpp
 *
 *  Created on: 22 Jan 2016
 *      Author: lubiedak
 */

#include "RandomProblemGenerator.h"

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

#include "../model/Node.h"

RandomProblemGenerator::RandomProblemGenerator(ProblemGenParams & params, Criteria& criteria) :
    params(params), criteria(criteria) {
  // TODO Auto-generated constructor stub

}

RandomProblemGenerator::~RandomProblemGenerator() {
  // TODO Auto-generated destructor stub
}

Problem RandomProblemGenerator::generate() {
  Problem p(criteria, Node(0, "Depot", 0, 0, 0));
  p.setCriteria(criteria);
  srand(time(NULL));
  for (uint16_t i = 1; i <= params.nodes; ++i) {
    Node n = Node(i, std::string("rand"), rand() % params.maxX, rand() % params.maxY,
        params.minDemand + rand() % (params.maxDemand - params.minDemand));
    p.addNode(n);
  }

  p.generateDistances();

  problem = p;
  return problem;
}

void RandomProblemGenerator::save(std::string dir, std::string fileName) {

  std::ofstream myfile;
  myfile.open((dir + fileName).c_str());
  myfile << problem.toString();
  myfile.close();
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}

ProblemGenParams initFromFile(std::string fileName) {
  ProblemGenParams params;
  std::ifstream file(fileName.c_str());
  std::string fileContent;
  getline(file, fileContent);
  std::vector<std::string> data = split(fileContent, ',');
  params.nodes = (uint16_t) std::stoi(data[0]);
  params.maxX = (uint16_t) std::stoi(data[1]);
  params.maxY = (uint16_t) std::stoi(data[2]);
  params.minDemand = (uint16_t) std::stoi(data[3]);
  params.maxDemand = (uint16_t) std::stoi(data[4]);
  return params;
}

