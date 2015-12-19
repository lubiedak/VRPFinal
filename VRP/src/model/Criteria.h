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

class Criteria : public Serialized {
public:

	Criteria(){}

	Criteria(uint16_t maxC, uint16_t maxD, uint16_t maxN,
			 uint16_t minC,	uint16_t minD, uint16_t minN);

	Criteria(uint16_t maxC, uint16_t maxD, uint16_t maxN);

	Criteria(const Criteria& c);

	Criteria& operator=(const Criteria& c);

	virtual ~Criteria(){};
	std::string toString();

	virtual std::string serialize();
	virtual bool deserialize(std::string);

	uint16_t maxCapacity(){return properties["maxCapacity"];}
	uint16_t minCapacity(){return properties["minCapacity"];}

	uint16_t maxDistance(){return properties["maxDistance"];}
	uint16_t minDistance(){return properties["minDistance"];}

	uint16_t maxNodes(){return properties["maxNodes"];}
	uint16_t minNodes(){return properties["minNodes"];}


private:
	std::map<std::string, uint16_t> properties;
};


#endif /* MODEL_CRITERIA_H_ */

