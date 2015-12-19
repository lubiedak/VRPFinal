/*
 * Criteria.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Criteria.h"

#include <sstream>
#include <string>

Criteria::Criteria( uint16_t maxC, uint16_t maxD, uint16_t maxN,
					uint16_t minC, uint16_t minD, uint16_t minN) {
	properties = std::map<std::string, uint16_t>();
	properties["maxCapacity"] = maxC;
	properties["maxDistance"] = maxD;
	properties["maxNodes"] = maxN;
	properties["minCapacity"] = minC;
	properties["minDistance"] = minD;
	properties["minNodes"] = minN;
	membersCount = 6;
}

Criteria::Criteria(uint16_t maxC, uint16_t maxD, uint16_t maxN) :
		Criteria(maxC, maxD, maxN, 0, 0, 0) {
	membersCount = 6;
}

Criteria::Criteria(const Criteria& c) {
	properties = c.properties;
	membersCount = 6;
}

Criteria& Criteria::operator =(const Criteria& c) {
	this->properties = c.properties;
	this->membersCount = c.membersCount;
	return *this;
}

std::string Criteria::toString() {
	std::stringstream oss;
	oss << std::string("class=Criteria");
	for (auto pair : properties) {
		oss << delimiter << pair.first << mapDelimiter << pair.second;
	}

	return oss.str();
}

std::string Criteria::serialize() {
	return toString();
}



bool Criteria::deserialize(std::string str) {
	std::map<std::string, std::string> values = parse(str);

	return true;
}


