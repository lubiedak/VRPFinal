/*
 * CycleCreator.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleCreator.h"

#include <cmath>

#include "../model/Criteria.h"

CycleCreator::CycleCreator(Problem p, Criteria c) :
		problem(p), criteria(c) {
}

CycleCreator::~CycleCreator() {
	// TODO Auto-generated destructor stub
}

bool CycleCreator::optimize(std::vector<Cycle>& cycles) {
	return true;
}

bool CycleCreator::create() {

	uint16_t size = countPossibleCycles();
	return true;
}

uint16_t CycleCreator::countPossibleCycles() {
	uint32_t N = countN(problem, criteria.maxNodes());

	uint16_t counter = 0;
	uint16_t baseCounter = 0;

	uint16_t cycleSize, cargo=0;
	for (uint32_t i = 1; i < N; ++i) {
		cycleSize = NumberOfSetBits(i);
		if (cycleSize >= criteria.minNodes() && cycleSize <= criteria.maxNodes()) {
			cargo = SumCargo(i, problem.getNodes());
			if (cargo > criteria.minCapacity() && cargo < criteria.maxCapacity()) {
				if (i & problem.getBiggestDemander()) {
					baseCounter++;
					counter++;
				} else {
					counter++;
				}
			}
		}
	}

	return counter;
}

unsigned CycleCreator::countN(Problem p, unsigned maxNodes) {
	return (unsigned) (pow(2.0, p.size()) - 1 - pow(2.0, p.size() - maxNodes));
}

uint32_t CycleCreator::NumberOfSetBits(int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

uint16_t CycleCreator::SumCargo( uint32_t set, const std::vector<Node>& nodes)
{
	uint16_t cargo = 0;
    for (uint16_t j = 0; j < nodes.size(); ++j) {
        cargo += (set & 1) * nodes[j].getDemand();
        set = set >> 1;
        if(!set)
        	break;
    }
    return cargo;
}
