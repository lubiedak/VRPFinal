/*
 * Criteria.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Criteria.h"
#include "serialization/Serialized.h"

#include <sstream>
#include <string>

Criteria::Criteria(uint16_t maxC, uint16_t maxD, uint16_t maxN, uint16_t minC, uint16_t minD, uint16_t minN) {
  properties = std::map<std::string, uint16_t>();
  properties["maxCapacity"] = maxC;
  properties["maxDistance"] = maxD;
  properties["maxNodes"] = maxN;
  properties["minCapacity"] = minC;
  properties["minDistance"] = minD;
  properties["minNodes"] = minN;
}

Criteria::Criteria(uint16_t maxC, uint16_t maxD, uint16_t maxN) :
    Criteria(maxC, maxD, maxN, 0, 0, 0) {
}

Criteria::Criteria(const Criteria& c) {
  properties = std::map<std::string, uint16_t>();
  properties = c.properties;
}

Criteria::Criteria(const crow::json::rvalue& json){
  crow::logger logger("criteria", crow::LogLevel::INFO);
        logger<<json;
  properties["maxCapacity"] = uint16_t(json["maxCapacity"].i());
  properties["maxDistance"] = uint16_t(json["maxDistance"].i());
  properties["maxNodes"] = uint16_t(json["maxNodes"].i());
  properties["minCapacity"] = uint16_t(json["minCapacity"].i());
  properties["minDistance"] = uint16_t(json["minDistance"].i());
  properties["minNodes"] = uint16_t(json["minNodes"].i());
}

Criteria& Criteria::operator =(const Criteria& c) {
  this->properties = c.properties;
  return *this;
}

std::string Criteria::toString() {
  std::stringstream oss;
  oss << std::string("class=Criteria");
  for (auto pair : properties) {
    oss << Serialized::delimiter << pair.first << Serialized::pairDelimiter << pair.second;
  }
  return oss.str();
}

crow::json::wvalue Criteria::toJson() {
  crow::json::wvalue json;
  for (auto pair : properties) {
    json[pair.first] = pair.second;
  }
  return json;
}
