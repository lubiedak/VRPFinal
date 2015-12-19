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

	Criteria(unsigned short maxC, unsigned short maxD, unsigned short maxN, unsigned short minC,
			unsigned short minD, unsigned short minN);

	Criteria(unsigned short maxC, unsigned short maxD, unsigned short maxN);

	Criteria(const Criteria& c);

	Criteria& operator=(const Criteria& c);

	virtual ~Criteria(){};
	std::string toString();

	virtual std::string serialize();
	virtual bool deserialize(std::string);

	unsigned short maxCapacity(){return properties["maxCapacity"];}
	unsigned short minCapacity(){return properties["minCapacity"];}

	unsigned short maxDistance(){return properties["maxDistance"];}
	unsigned short minDistance(){return properties["minDistance"];}

	unsigned short maxNodes(){return properties["maxNodes"];}
	unsigned short minNodes(){return properties["minNodes"];}


private:
	std::map<std::string, short unsigned> properties;
};


#endif /* MODEL_CRITERIA_H_ */

