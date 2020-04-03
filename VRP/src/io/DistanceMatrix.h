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
namespace matrix
{
    const int BEGIN = 3;
    const int X = 1;
    const int Y = 2;
}

class DistanceMatrix {
public:
  DistanceMatrix() {}
  DistanceMatrix(const std::string& fileName);
  ~DistanceMatrix() = default;

  void readFromFile(const std::string& fileName);
private:
  std::vector<std::vector<int>> matrix;
  std::vector<Node> nodes;
};
#endif