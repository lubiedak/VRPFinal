/*
 * ProblemLoader.cpp
 *
 *  Created on: 17 Jan 2016
 *      Author: lubiedak
 */

#include "ProblemLoader.h"

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

#include "../model/Node.h"
#include "../model/serialization/CriteriaDao.h"

ProblemLoader::ProblemLoader(const std::string& fileName) {
  this->fileName = fileName;
}

ProblemLoader::~ProblemLoader() {
  // TODO Auto-generated destructor stub
}

Problem ProblemLoader::load() {
  content = readContent();

  loadCriteria();
  loadNodes();
  p.analyze();
  return p;
}

std::vector<std::string> ProblemLoader::readContent() {
  std::ifstream file(fileName.c_str());
  std::string str;
  std::vector<std::string> lines;
  while (std::getline(file, str)) {
    lines.push_back(str);
  }
  return lines;
}

std::vector<std::string> ProblemLoader::getLinesContaining(const std::string& str) {
  auto it = content.begin();

  std::vector<std::string> requestedLines;
  while (it != content.end()) {
    if ((*it).find(str) != std::string::npos)
      requestedLines.push_back((*it));
    ++it;
  }

  return requestedLines;
}

/*
 * TODO: clever way of implementing these 2 functions
 */
LoadResult ProblemLoader::loadCriteria() {
  std::vector<std::string> criteria = getLinesContaining("class=Criteria");
  LoadResult result(ERROR);
  CriteriaDao c;
  switch (criteria.size()) {
  case 0:
    result.addMessage("ERROR: Can't find criteria class");
    break;
  case 1:

    if (c.deserialize(criteria[0])) {
      p.setCriteria(c.getCriteria());
      return LoadResult(SUCCESFUL);
    } else {
      result.addMessage("ERROR: Could not parse deserialize criteria. Input: " + criteria[0]);
      break;
    }
    break;
  default:
    result.addMessage("ERROR: Too many criteria elements?");
    break;
  }
  return result;
}

LoadResult ProblemLoader::loadNodes() {
  std::vector<std::string> nodes = getLinesContaining("class=Node");

  LoadResult result(ERROR);

  if (nodes.size() < 5) {
    result.addMessage("ERROR: Not enough nodes. Problem size less than 5.");
  } else {
    for (auto n : nodes) {
      Node node;
      if (!node.deserialize(n)) {
        result.addMessage("ERROR: When parsing node: " + n);
      } else {
        p.addNode(node);
      }
    }
  }

  return result;
}
