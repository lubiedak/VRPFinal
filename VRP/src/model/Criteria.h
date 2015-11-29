/*
 * Criteria.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef MODEL_CRITERIA_H_
#define MODEL_CRITERIA_H_

#include <string>

#include "serialization/Serialized.h"

class Criteria : public Serialized{
public:

	Criteria(){}

	Criteria(unsigned maxC, unsigned minC, unsigned maxD,
			 unsigned minD,	unsigned maxN, unsigned minN) :
		maxCapacity(maxC), minCapacity(minC), maxDistance(maxD),
		minDistance(minD), maxNodes(maxN), 	  minNodes(minN) {}

	Criteria(unsigned maxC, unsigned maxD, unsigned maxN) :
		maxCapacity(maxC), minCapacity(0), maxDistance(maxD),
		minDistance(0),    maxNodes(maxN), minNodes(0) {}

	virtual ~Criteria(){};
	std::string toString();


	unsigned maxCapacity;
	unsigned minCapacity;

	unsigned maxDistance;
	unsigned minDistance;

	unsigned maxNodes;
	unsigned minNodes;


private:
};


#endif /* MODEL_CRITERIA_H_ */

