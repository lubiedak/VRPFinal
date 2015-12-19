/*
 * Criteria.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Criteria.h"

#include <sstream>
#include <string>

Criteria::Criteria(unsigned maxC, unsigned maxD, unsigned maxN, unsigned minC,
		unsigned minD, unsigned minN) {
	properties = std::map<std::string, unsigned>();
	properties["maxCapacity"] = maxC;
	properties["maxDistance"] = maxD;
	properties["maxNodes"] = maxN;
	properties["minCapacity"] = minC;
	properties["minDistance"] = minD;
	properties["minNodes"] = minN;
}

Criteria::Criteria(unsigned maxC, unsigned maxD, unsigned maxN) :
		Criteria(maxC, maxD, maxN, 0, 0, 0) {
}

Criteria::Criteria(const Criteria& c) {
	properties = c.properties;
}

Criteria& Criteria::operator =(const Criteria& c) {
	this->properties = c.properties;
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


