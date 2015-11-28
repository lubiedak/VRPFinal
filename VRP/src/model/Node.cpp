/*
 * Node.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Node.h"

Node::Node() {
	this->id = 0;
	this->name = "Node0123";
	this->x = 1;
	this->y = 2;
	this->demand = 3;
}

Node::~Node() {
}

Node::Node(unsigned id, std::string name, unsigned x, unsigned y,
		unsigned demand) {
	this->id = id;
	this->name = name;
	this->x = x;
	this->y = y;
	this->demand = demand;
}
