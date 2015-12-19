/*
 * Criteria.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Criteria.h"

#include <sstream>
#include <string>

Criteria::Criteria(unsigned short maxC, unsigned short maxD, unsigned short maxN, unsigned short minC,
		unsigned short minD, unsigned short minN) {
	properties = std::map<std::string, short unsigned>();
	properties["maxCapacity"] = maxC;
	properties["maxDistance"] = maxD;
	properties["maxNodes"] = maxN;
	properties["minCapacity"] = minC;
	properties["minDistance"] = minD;
	properties["minNodes"] = minN;
	membersCount = 6;
}

Criteria::Criteria(unsigned short maxC, unsigned short maxD, unsigned short maxN) :
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


