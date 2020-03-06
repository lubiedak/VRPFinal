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
  Node& operator=(const Node&);
  bool operator==(const Node&);
  virtual ~Node();

  Node(uint32_t id, const std::string& name, int32_t x, int32_t y, uint16_t demand);

  std::string toString();
  crow::json::wvalue toJson();

  virtual std::string serialize();
  virtual bool deserialize(std::string);

  uint16_t getDemand() const {
    return demand;
  }
  void setDemand(uint16_t demand) {
    this->demand = demand;
  }
  uint32_t getId() const {
    return id;
  }
  void setId(uint32_t id) {
    this->id = id;
  }
  const std::string& getName() const {
    return name;
  }
  void setName(const std::string& name) {
    this->name = name;
  }
  int32_t getX() const {
    return x;
  }
  void setX(int32_t x) {
    this->x = x;
  }
  int32_t getY() const {
    return y;
  }
  void setY(int32_t y) {
    this->y = y;
  }
  bool isDepot(){
    return 0 == name.compare("Depot");
  }

private:
  uint32_t id;
  std::string name;

  int32_t x;
  int32_t y;
  uint16_t demand;

};

#endif /* MODEL_NODE_H_ */
