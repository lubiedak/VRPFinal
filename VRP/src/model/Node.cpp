/*
 * Node.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Node.h"
#include <stdexcept>
#include <iostream>

Node::Node() :
    Node(0, 0, std::string("node"), 0, 0, 0) {
}

Node::Node(const crow::json::rvalue& json) {
  id = json["id"].i();
  distance_id = json["distance_id"].i();
  x = json["x"].i();
  y = json["y"].i();
  demand = json["demand"].i();
  name = json["name"].s();
  membersCount = 6;
}

Node::Node(uint32_t id, const std::string& name, int32_t x, int32_t y, uint16_t demand) :
    id(id), distance_id(0), name(name), x(x), y(y), demand(demand) {
  membersCount = 6;
}

Node::Node(uint32_t id, uint32_t distance_id, const std::string& name, int32_t x, int32_t y, uint16_t demand) :
    id(id), distance_id(distance_id), name(name), x(x), y(y), demand(demand) {
  membersCount = 6;
}

Node::Node(const Node& n) :
    Node(n.id, n.distance_id, n.name, n.x, n.y, n.demand) {
  membersCount = n.membersCount;
}

Node& Node::operator =(const Node& n) {
  id = n.id;
  distance_id = n.distance_id;
  name = n.name;
  x = n.x;
  y = n.y;
  demand = n.demand;
  membersCount = n.membersCount;
  return *this;
}

bool Node::operator ==(const Node& n) {
  return id == n.id && distance_id == n.distance_id && name.compare(n.name) == 0 
  && x == n.x && y == n.y && demand == n.demand;
}

std::string Node::toString() {
  std::stringstream oss;
  oss << std::string("class=Node");
  oss << delimiter << "id" << pairDelimiter << id;
  oss << delimiter << "distance_id" << pairDelimiter << distance_id;
  oss << delimiter << "name" << pairDelimiter << name;
  oss << delimiter << "x" << pairDelimiter << x;
  oss << delimiter << "y" << pairDelimiter << y;
  oss << delimiter << "demand" << pairDelimiter << demand;

  return oss.str();
}

crow::json::wvalue Node::toJson() {
  crow::json::wvalue json;

  json["id"] = id;
  json["distance_id"] = distance_id;
  json["name"] = name;
  json["x"] =  x;
  json["y"] = y;
  json["demand"] =  demand;

  return json;
}

std::string Node::serialize() {
  return toString();
}

bool Node::deserialize(std::string nodeStr) {
  std::map<std::string, std::string> params = parse(nodeStr);

  if (params.at("class").compare("Node") != 0)
    return false;

  Node nodeCopy = *this;

  std::string err = "DESERIALIZATION ERROR of ";

  try {
    id = (uint32_t) (std::stoi(params.at("id")));
  } catch (const std::out_of_range& e) {
    std::cout << err << nodeStr << " field 'id' doesn't exist" << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << err << nodeStr << " field 'id'" << std::endl;
  }

  try {
    distance_id = (uint32_t) (std::stoi(params.at("distance_id")));
  } catch (const std::out_of_range& e) {
    std::cout << err << nodeStr << " field 'distance_id' doesn't exist" << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << err << nodeStr << " field 'distance_id'" << std::endl;
  }

  try {
    name = params["name"];
  } catch (const std::out_of_range& e) {
    std::cout << err << nodeStr << " field 'name' doesn't exist" << std::endl;
  }

  try {
    x = (int32_t) (std::stoi(params["x"]));
  } catch (const std::out_of_range& e) {
    std::cout << err << nodeStr << " field 'x' doesn't exist" << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << err << nodeStr << " field 'x'" << std::endl;
  }

  try {
    y = (int32_t) (std::stoi(params["y"]));
  } catch (const std::out_of_range& e) {
    std::cout << err << nodeStr << " field 'y' doesn't exist" << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << err << nodeStr << " field 'y'" << std::endl;
  }

  try {
    demand = (uint16_t) (std::stoi(params["demand"]));
  } catch (const std::out_of_range& e) {
    std::cout << err << nodeStr << " field 'demand' doesn't exist" << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << err << nodeStr << " field 'demand'" << std::endl;
  }

  return true;
}

