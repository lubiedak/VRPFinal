/*
 * Cycle.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef CYCLE_H_
#define CYCLE_H_

#include <string>
#include <vector>
#include "Node.h"
#include "Edge.h"
#include "serialization/Serialized.h"

class Cycle: public Serialized {
public:
  Cycle();
  Cycle(const Cycle& c);
  Cycle& operator=(const Cycle&);
  bool operator<(const Cycle&) const;
  virtual ~Cycle();

  std::string toString();
  crow::json::wvalue toJson();

  uint16_t selfOptimize(const std::vector<std::vector<uint16_t>>& distances, std::vector<std::vector<int>>& perms);

  virtual std::string serialize();
  virtual bool deserialize(std::string);

  void setDemand(uint16_t demand) {
    this->demand = demand;
  }
  uint16_t getDemand() const {
    return demand;
  }

  void setDistance(uint16_t distance) {
    this->distance = distance;
  }
  uint16_t getDistance() const {
    return distance;
  }

  void setId(uint32_t id) {
    this->id = id;
  }
  uint32_t getId() const {
    return id;
  }

  void setNodes(const std::vector<Node>& nodes) {
    this->nodes = nodes;
  }

  bool contains(uint16_t nodeId) const;

  void setDemandToDistRatioRank(int position, int size) {
    demandToDistRatioRank = position*100.0f/size;
  }

  void setDistanceRank(int position, int size) {
    distanceRank = position*100.0f/size;
  }

  void setDemandRank(int position, int size) {
    demandRank = position*100.0f/size;
  }

  float getDemandToDistRatio() const {
    return demandToDistRatio;
  }

private:
  uint32_t id;
  uint16_t distance;
  uint16_t demand;
  uint16_t capacity;
//useful metrics
  float distCoef;
  float demandToDistRatio;

  float demandToDistRatioRank;
  float distanceRank;
  float demandRank;
  
  std::vector<Node> nodes;
  std::vector<Edge> edges;
  

  void checkPermSize(std::vector<std::vector<int>>& perms);
  uint16_t countMinimumDistance(const std::vector<std::vector<uint16_t> >& distances,
      const std::vector<std::vector<int>>& perms);
};

#endif /* CYCLE_H_ */
