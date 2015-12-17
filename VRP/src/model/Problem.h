/*
 * Problem.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef MODEL_PROBLEM_H_
#define MODEL_PROBLEM_H_

#include <vector>

#include "Criteria.h"
#include "Node.h"
#include "Cycle.h"

class Problem {
public:
	Problem();
	virtual ~Problem();
	void analyze();

private:

	unsigned findBiggestDemander();
	unsigned sumDemands();

	unsigned biggestDemander;
	unsigned demandsSum;

	Criteria criteria;
	std::vector<Node> nodes;
	std::vector<Cycle> cycles;
	std::vector< std::vector<short> > distances;
};

#endif /* MODEL_PROBLEM_H_ */
