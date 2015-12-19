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
		unsigned demand) : id(id), name(name), x(x), y(y), demand(demand) {
}
Node::Node(const Node& n) : Node(n.id, n.name, n.x, n.y, n.demand) {
}

Node& Node::operator =(const Node& n) {
	this->id = n.id;
	this->name = n.name;
	this->x = n.x;
	this->y = n.y;
	this->demand = n.demand;
	return *this;
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


