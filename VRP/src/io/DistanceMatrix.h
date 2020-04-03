/*
 * DistanceMatrix.h
 *
 *  Created on: 31 Mar 2020
 *      Author: lubiedak
 */

#ifndef IO_DISTANCEMATRIX_H_
#define IO_DISTANCEMATRIX_H_

#include <string>
#include <vector>
#include "../model/Node.h"

class DistanceMatrix {
public:
  DistanceMatrix() {}
  DistanceMatrix(const std::string& fileName);
  ~DistanceMatrix() = default;

private:
  void readFromFile(const std::string& fileName);
  std::vector<std::vector<int>> matrix;
  std::vector<Node> nodes;
};
#endif