/*
 * CyclesSet.cpp
 *
 *  Created on: 28 Dec 2015
 *      Author: lubiedak
 */

#include "CyclesSet.h"

CyclesSet::CyclesSet(const Cycle& cycle, uint16_t firstElem, uint16_t size) :
		id(cycle.getId()), distance(cycle.getDistance()) {
	cycles = new uint16_t[size];
	cycles[0] = firstElem;
}

CyclesSet::~CyclesSet() {
	delete[] cycles;
}

