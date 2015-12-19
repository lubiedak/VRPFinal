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
	Cycle(const Cycle& c);
	Cycle& operator=(const Cycle&);
	virtual ~Cycle();

	std::string toString();

	virtual std::string serialize();
	virtual bool deserialize(std::string);


private:
	uint32_t id;
	uint16_t distance;
	uint16_t demand;
	uint16_t capacity;
    std::vector<Node> nodes;
};

#endif /* CYCLE_H_ */
