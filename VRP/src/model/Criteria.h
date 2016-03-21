/*
 * Criteria.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef MODEL_CRITERIA_H_
#define MODEL_CRITERIA_H_

#include <string>
#include <map>

class Criteria {
public:

  Criteria() {
  }

  Criteria(uint16_t maxC, uint16_t maxD, uint16_t maxN, uint16_t minC, uint16_t minD, uint16_t minN);

  Criteria(uint16_t maxC, uint16_t maxD, uint16_t maxN);

  Criteria(const Criteria& c);

  Criteria& operator=(const Criteria& c);

  virtual ~Criteria() {
  }
  ;

  std::string toString();

  uint16_t maxCapacity() const {
    return properties.at("maxCapacity");
  }
  uint16_t minCapacity() const {
    return properties.at("minCapacity");
  }

  uint16_t maxDistance() const {
    return properties.at("maxDistance");
  }
  uint16_t minDistance() const {
    return properties.at("minDistance");
  }

  uint16_t maxNodes() const {
    return properties.at("maxNodes");
  }
  uint16_t minNodes() const {
    return properties.at("minNodes");
  }

  void setMinCapacity(uint16_t minC){
    properties["minCapacity"] = minC;
  }

private:
  std::map<std::string, uint16_t> properties;
};

#endif /* MODEL_CRITERIA_H_ */

