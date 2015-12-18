/*
 * Node.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Node.h"

Node::Node() : Node(0, std::string("node"), 0, 0, 0) {
}

Node::~Node() {
}

Node::Node(unsigned id, const std::string& name, unsigned x, unsigned y,
		unsigned demand) {
	this->id = id;
	this->name = name;
	this->x = x;
	this->y = y;
	this->demand = demand;
}

std::string Node::toString() {
	std::stringstream oss;
	oss << std::string("class=Node");
	oss << delimiter << "id"     << mapDelimiter << id;
	oss << delimiter << "name"   << mapDelimiter << name;
	oss << delimiter << "x"      << mapDelimiter << x;
	oss << delimiter << "y"      << mapDelimiter << y;
	oss << delimiter << "demand" << mapDelimiter << demand;

	return oss.str();
}

std::string Node::serialize() {
	return toString();
}

bool Node::deserialize(std::string allocator) {
	return true;
}

