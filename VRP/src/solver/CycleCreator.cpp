/*
 * CycleCreator.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "CycleCreator.h"

#include <cmath>

#include "../model/Criteria.h"
#include "../model/Node.h"

CycleCreator::CycleCreator(Problem p, Criteria c) :
		problem(p), criteria(c) {
	permGen = PermutationGen<int>(c.maxNodes());
}

CycleCreator::~CycleCreator() {
	// TODO Auto-generated destructor stub
}

bool CycleCreator::optimize(std::vector<Cycle>& cycles) {
	return true;
}

/**
 * cycleId is binary representation of cycle from vector of cycles
 * 5 ==> 101 ==> Node_0 and Node_2
 */
bool CycleCreator::create() {

	std::vector<uint32_t> cycleIds = countPossibleCycles();
	std::vector<Cycle> cycles(cycleIds.size());
	std::vector<std::vector<int>> perms = permGen.getFullPermTable();

	for(uint16_t i = 0 ; i < cycleIds.size(); ++i){
		cycles[i].setId(cycleIds[i]);
		cycles[i].setDemand(SumDemand(i, problem.getNodes()));
		cycles[i].setNodes(problem.getNodesAndDepot(cycleIds[i]));
		cycles[i].selfOptimize(problem.getDistances(), perms);
	}


	return true;
}

std::vector<uint32_t> CycleCreator::countPossibleCycles() {
	uint32_t N = countN(problem, criteria.maxNodes());

	std::vector<uint32_t> cycleIds(0);
	cycleIds.reserve(problem.approxCyclesCount());
	uint16_t cycleSize=0, cargo=0;

	for (uint32_t id = 1; id <= N; ++id) {
		cycleSize = NumberOfSetBits(id);
		if (cycleSize >= criteria.minNodes() && cycleSize <= criteria.maxNodes()) {
			cargo = SumDemand(id, problem.getNodes());
			if (cargo > criteria.minCapacity() && cargo < criteria.maxCapacity()) {
				cycleIds.push_back(id);
			}
		}
	}
	return cycleIds;
}

unsigned CycleCreator::countN(Problem p, unsigned maxNodes) {
	return (unsigned) (pow(2.0, p.size()) - pow(2.0, p.size() - maxNodes));
}

uint32_t CycleCreator::NumberOfSetBits(int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

uint16_t CycleCreator::SumDemand( uint32_t set, const std::vector<Node>& nodes)
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
