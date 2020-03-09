/*
 * Edge.cpp
 *
 *  Created on: 09 Mar 2020
 *      Author: lubiedak
 */
#include "Edge.h"

Edge::Edge(const Edge &e) : id(e.id), source(e.source), target(e.target){}
Edge::Edge(std::string id, int32_t source, int32_t target) : id(id), source(source), target(target){}

crow::json::wvalue Edge::toJsonForDrawing(){
  crow::json::wvalue json;
  json["id"] = id;
  json["source"] = source;
  json["target"] = target;
  
  return json;
}
