/*
 * Node.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

#include <string>
#include "serialization/Serialized.h"
#include <stdint.h>
#include "../io/crow_all.h"

class Node: public Serialized {
public:
  Node();
  Node(const Node& n);
  Node(const crow::json::rvalue& json);
  Node& operator=(const Node&);
  bool operator==(const Node&);
  virtual ~Node();

  Node(uint32_t id, uint32_t distance_id, const std::string& name, int32_t x, int32_t y, uint16_t demand);

  Node(uint32_t id, const std::string& name, int32_t x, int32_t y, uint16_t demand);

  std::string toString();
  crow::json::wvalue toJson();

  virtual std::string serialize();
  virtual bool deserialize(std::string);

  uint16_t getDemand() const {
    return demand;
  }
  uint32_t getId() const {
    return id;
  }
  uint32_t getDistanceId() const {
    return id;
  }
  int32_t getX() const {
    return x;
  }
  int32_t getY() const {
    return y;
  }
  bool isDepot(){
    return 0 == name.compare("Depot");
  }

private:
  uint32_t id;
  uint32_t distance_id;
  std::string name;

  int32_t x;
  int32_t y;
  uint16_t demand;
};

#endif /* MODEL_NODE_H_ */
