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

	uint16_t selfOptimize(const std::vector<std::vector<uint16_t>>& distances,
						  std::vector<std::vector<int>>& perms);

	virtual std::string serialize();
	virtual bool deserialize(std::string);

	void setDemand(uint16_t demand) {this->demand = demand;}
	void setDistance(uint16_t distance) {this->distance = distance;}
	void setId(uint32_t id) {this->id = id;}
	void setNodes(const std::vector<Node>& nodes) {this->nodes = nodes;}

private:
	uint32_t id;
	uint16_t distance;
	uint16_t demand;
	uint16_t capacity;
    std::vector<Node> nodes;

    void checkPermSize(std::vector<std::vector<int>>& perms);
    uint16_t countMinimumDistance(const std::vector<std::vector<uint16_t> >& distances,
    							  const std::vector<std::vector<int>>& perms);
};

#endif /* CYCLE_H_ */
