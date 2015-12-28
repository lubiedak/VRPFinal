/*
 * Node.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Node.h"

Node::Node() :
		Node(0, std::string("node"), 0, 0, 0) {
}

Node::~Node() {
}

Node::Node(uint32_t id, const std::string& name, int32_t x, int32_t y, uint16_t demand) :
		id(id), name(name), x(x), y(y), demand(demand) {
	membersCount = 5;
}
Node::Node(const Node& n) :
		Node(n.id, n.name, n.x, n.y, n.demand) {
	membersCount = n.membersCount;
}

Node& Node::operator =(const Node& n) {
	this->id = n.id;
	this->name = n.name;
	this->x = n.x;
	this->y = n.y;
	this->demand = n.demand;
	this->membersCount = n.membersCount;
	return *this;
}

std::string Node::toString() {
	std::stringstream oss;
	oss << std::string("class=Node");
	oss << delimiter << "id" << mapDelimiter << id;
	oss << delimiter << "name" << mapDelimiter << name;
	oss << delimiter << "x" << mapDelimiter << x;
	oss << delimiter << "y" << mapDelimiter << y;
	oss << delimiter << "demand" << mapDelimiter << demand;

	return oss.str();
}

std::string Node::serialize() {
	return toString();
}

bool Node::deserialize(std::string allocator) {
	return true;
}

