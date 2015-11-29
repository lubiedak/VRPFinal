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

	Criteria(unsigned maxC, unsigned maxD, unsigned maxN, unsigned minC,
			unsigned minD, unsigned minN);

	Criteria(unsigned maxC, unsigned maxD, unsigned maxN);

	virtual ~Criteria(){};
	std::string toString();

	virtual std::string serialize();
	virtual bool deserialize(std::string);


	std::map<std::string, unsigned> properties;

	unsigned maxCapacity(){return properties["maxCapacity"];}
	unsigned minCapacity(){return properties["minCapacity"];}

	unsigned maxDistance(){return properties["maxDistance"];}
	unsigned minDistance(){return properties["minDistance"];}

	unsigned maxNodes(){return properties["maxNodes"];}
	unsigned minNodes(){return properties["minNodes"];}


private:

};


#endif /* MODEL_CRITERIA_H_ */

