/*
 * Serializator.h
 *
 *  Created on: 17 Dec 2015
 *      Author: lubiedak
 */

#ifndef MODEL_SERIALIZATION_SERIALIZATOR_H_
#define MODEL_SERIALIZATION_SERIALIZATOR_H_
#include "Serialized.h"


class Serializator {
public:
	Serializator();
	virtual ~Serializator();

	bool serialize();
};

#endif /* MODEL_SERIALIZATION_SERIALIZATOR_H_ */
