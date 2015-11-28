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

class Cycle {
public:
	Cycle();
	virtual ~Cycle();

private:
    unsigned id;
    unsigned distance;
    unsigned demand;
    unsigned capacity;
    std::vector<Node> nodes;
};

#endif /* CYCLE_H_ */
