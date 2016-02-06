/*
 * ProblemsForTest.cpp
 *
 *  Created on: 9 Jan 2016
 *      Author: lubiedak
 */

#include "ProblemsForTest.h"

#include <vector>

#include "../../model/Criteria.h"
#include "../../model/Node.h"
#include "../../model/Problem.h"

Problem problem5Nodes() {
  Criteria criteria = Criteria(1000, 20000, 5);

  std::vector<Node> nodes = std::vector<Node>();
  Node depot(0, "Depot", 0, 0, 0);
  nodes.push_back(Node(1, "X1", 10, 60, 301));
  nodes.push_back(Node(2, "X2", 20, 70, 300));
  nodes.push_back(Node(3, "X3", 120, 120, 300));
  nodes.push_back(Node(4, "X4", 120, 130, 300));
  nodes.push_back(Node(5, "X5", 140, 130, 300));

  Problem problem = Problem(criteria, depot, nodes);
  problem.generateDistances();
  return problem;
}

Problem problem6Nodes() {
  Criteria criteria = Criteria(1000, 20000, 5);

  std::vector<Node> nodes = std::vector<Node>();
  Node depot(0, "Depot", 0, 0, 0);
  nodes.push_back(Node(1, "X1", 10, 60, 220));
  nodes.push_back(Node(2, "X2", 20, 70, 220));
  nodes.push_back(Node(3, "X3", 120, 120, 220));
  nodes.push_back(Node(4, "X4", 120, 130, 220));
  nodes.push_back(Node(5, "X5", 140, 130, 220));
  nodes.push_back(Node(6, "X6", 140, 170, 220));

  Problem problem = Problem(criteria, depot, nodes);
  problem.generateDistances();
  return problem;
}

Problem problem10Nodes() {
  Criteria criteria = Criteria(1000, 20000, 5);

  std::vector<Node> nodes = std::vector<Node>();
  Node depot(0, "Depot", 0, 0, 0);
  nodes.push_back(Node(1, "X1", 10, 60, 301));
  nodes.push_back(Node(2, "X2", 20, 70, 300));
  nodes.push_back(Node(3, "X3", 120, 120, 300));
  nodes.push_back(Node(4, "X4", 120, 130, 300));
  nodes.push_back(Node(5, "X5", 140, 130, 300));
  nodes.push_back(Node(6, "X6", 420, 120, 300));
  nodes.push_back(Node(7, "X7", 420, 130, 300));
  nodes.push_back(Node(8, "X8", 440, 130, 300));
  nodes.push_back(Node(9, "X9", 220, 120, 300));
  nodes.push_back(Node(10, "X10", 220, 130, 300));

  Problem problem = Problem(criteria, depot, nodes);
  problem.generateDistances();
  return problem;
}

Problem problem20Nodes() {
  Criteria criteria = Criteria(1000, 20000, 5, 600, 0, 0);

  std::vector<Node> nodes = std::vector<Node>();
  Node depot(0, "Depot", 0, 0, 0);
  nodes.push_back(Node(1, "X1", 10, 60, 201));
  nodes.push_back(Node(2, "X2", 20, 70, 199));
  nodes.push_back(Node(3, "X3", 120, 120, 199));
  nodes.push_back(Node(4, "X4", 120, 130, 199));
  nodes.push_back(Node(5, "X5", 140, 130, 199));
  nodes.push_back(Node(6, "X6", 420, 120, 199));
  nodes.push_back(Node(7, "X7", 420, 130, 199));
  nodes.push_back(Node(8, "X8", 440, 130, 199));
  nodes.push_back(Node(9, "X9", 220, 120, 199));
  nodes.push_back(Node(10, "X10", 220, 130, 199));
  nodes.push_back(Node(11, "X11", 110, 80, 199));
  nodes.push_back(Node(12, "X12", 120, 90, 199));
  nodes.push_back(Node(13, "X13", 160, 120, 199));
  nodes.push_back(Node(14, "X14", 160, 130, 199));
  nodes.push_back(Node(15, "X15", 180, 130, 199));
  nodes.push_back(Node(16, "X16", 480, 120, 199));
  nodes.push_back(Node(17, "X17", 480, 130, 199));
  nodes.push_back(Node(18, "X18", 540, 130, 199));
  nodes.push_back(Node(19, "X19", 320, 120, 199));
  nodes.push_back(Node(20, "X20", 320, 130, 199));

  Problem problem = Problem(criteria, depot, nodes);
  problem.generateDistances();
  return problem;
}

