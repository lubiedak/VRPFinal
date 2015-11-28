/*
 * Node.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Node.h"

Node::Node() {
}

Node::~Node() {
}

Node::Node(std::string id, std::string name, unsigned x, unsigned y, unsigned demand) {
	this->id = id;
	this->name = name;
	this->x = x;
	this->y = y;
	this->demand = demand;
}
