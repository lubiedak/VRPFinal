/*
 * CyclesSet.cpp
 *
 *  Created on: 28 Dec 2015
 *      Author: lubiedak
 */

#include "CyclesSet.h"

CyclesSet::CyclesSet(const Cycle& cycle, uint16_t firstElem, uint16_t size) :
		id(cycle.getId()), distance(cycle.getDistance()), size(size) {
	cycles = new uint16_t[size];
	cycles[0] = firstElem;
}

CyclesSet::CyclesSet(uint32_t id, uint16_t distance, uint16_t size) :
		id(id), distance(distance), size(size) {
	cycles = new uint16_t[size];
}

CyclesSet::~CyclesSet() {
	delete[] cycles;
}

std::string CyclesSet::toString() {
	/*
	 * We dont want to extend Serialized class here;
	 */
	char delimiter = ',';
	char mapDelimiter = '=';
	std::stringstream oss;
	oss << std::string("class=CyclesSet");
	oss << delimiter << "id" << mapDelimiter << id;
	oss << delimiter << "distance" << mapDelimiter << distance;

	for (uint16_t i = 0; i < size; ++i) {
		oss << delimiter << "cycleId" << i << mapDelimiter << cycles[i];
	}

	return oss.str();
}
