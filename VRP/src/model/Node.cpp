/*
 * Node.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Node.h"
#include <stdexcept>
#include <iostream>

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

bool Node::operator ==(const Node& n) {
	return id == n.id && name.compare(n.name) == 0 && x == n.x && y == n.y && demand == n.demand;
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


bool Node::deserialize(std::string nodeStr) {
	std::map<std::string, std::string> params = parse(nodeStr);

	if(params.at("class").compare("Node") != 0)
		return false;

	Node nodeCopy = *this;

	std::string err = "DESERIALIZATION ERROR of ";

	try{
		id = (uint32_t)(std::stoi(params.at("id")));
	}catch(const std::out_of_range& e){
		std::cout<<err<<nodeStr<<" field 'id' doesn't exist"<<std::endl;
	}catch(const std::invalid_argument& e){
		std::cout<<err<<nodeStr<<" field 'id'"<<std::endl;
	}

	try{
		name = params["name"];
	}catch(const std::out_of_range& e){
		std::cout<<err<<nodeStr<<" field 'name' doesn't exist"<<std::endl;
	}

	try{
		x = (int32_t)(std::stoi(params["x"]));
	}catch(const std::out_of_range& e){
		std::cout<<err<<nodeStr<<" field 'x' doesn't exist"<<std::endl;
	}catch(const std::invalid_argument& e){
		std::cout<<err<<nodeStr<<" field 'x'"<<std::endl;
	}

	try{
		y = (int32_t)(std::stoi(params["y"]));
	}catch(const std::out_of_range& e){
		std::cout<<err<<nodeStr<<" field 'y' doesn't exist"<<std::endl;
	}catch(const std::invalid_argument& e){
		std::cout<<err<<nodeStr<<" field 'y'"<<std::endl;
	}

	try{
		demand = (uint16_t)(std::stoi(params["demand"]));
	}catch(const std::out_of_range& e){
		std::cout<<err<<nodeStr<<" field 'demand' doesn't exist"<<std::endl;
	}catch(const std::invalid_argument& e){
		std::cout<<err<<nodeStr<<" field 'demand'"<<std::endl;
	}

	return true;
}

