/*
 * Node.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

#include <string>

class Node {
public:
	virtual ~Node();

	Node(unsigned id, std::string name, unsigned x, unsigned y, unsigned demand);


	unsigned getId() const {return id;}
	void setId(unsigned id) {this->id = id;}
	std::string getName() const {return name;}
	void setName(std::string name) {this->name = name;}
	unsigned getX() const {return x;}
	void setX(unsigned x) {this->x = x;}
	unsigned getY() const {return y;}
	void setY(unsigned y) {this->y = y;}
	unsigned getDemand() const {return demand;}
	void setDemand(unsigned demand) {this->demand = demand;}

private:
	unsigned id;
	std::string name;

	unsigned x;
	unsigned y;
	unsigned demand;

};

#endif /* MODEL_NODE_H_ */