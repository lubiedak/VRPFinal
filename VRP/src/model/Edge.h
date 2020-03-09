/*
 * Edge.h
 *
 *  Created on: 09 Mar 2020
 *      Author: lubiedak
 */

#ifndef MODEL_EDGE_H_
#define MODEL_EDGE_H_


#include "../io/crow_all.h"
#include <string>

class Edge {
public:
  Edge(){};
  Edge(std::string id, int32_t source, int32_t target);
  Edge(const Edge& e);
  virtual ~Edge(){};

  crow::json::wvalue toJsonForDrawing();

private:
  std::string id;
  int32_t source;
  int32_t target;
};

#endif /* MODEL_EDGE_H_ */
