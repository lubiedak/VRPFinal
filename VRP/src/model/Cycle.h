/*
 * Cycle.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef CYCLE_H_
#define CYCLE_H_

#include <string>
#include <vector>
#include "Node.h"
#include "serialization/Serialized.h"

class Cycle : public Serialized  {
public:
	Cycle();
	virtual ~Cycle();

	std::string toString();

	virtual std::string serialize();
	virtual bool deserialize(std::string);


private:
    unsigned id;
    unsigned distance;
    unsigned demand;
    unsigned capacity;
    std::vector<Node> nodes;
};

#endif /* CYCLE_H_ */
