/*
 * Criteria.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Criteria.h"

#include <sstream>
#include <string>

Criteria::Criteria(unsigned maxC, unsigned minC, unsigned maxD, unsigned minD,
		unsigned maxN, unsigned minN) {
	properties = std::map<std::string, unsigned>();
	properties["maxCapacity"] = maxC;
	properties["minCapacity"] = minC;
	properties["maxDistance"] = maxD;
	properties["minDistance"] = minD;
	properties["maxNodes"] = maxN;
	properties["minNodes"] = minN;
}

Criteria::Criteria(unsigned maxC, unsigned maxD, unsigned maxN) {
	Criteria(maxC, 0, maxD, 0, maxN, 0);
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

