/*
 * ProblemTest.h
 *
 *  Created on: 18 Dec 2015
 *      Author: lubiedak
 */

#ifndef TEST_PROBLEMTEST_H_
#define TEST_PROBLEMTEST_H_

#include "../model/Problem.h"

#include <iostream>
#include <string>

#include "../solver/CycleCreator.h"
#include "../solver/CycleConnector.h"
#include "../solver/Solution.h"
#include "resources/ProblemsForTest.h"


void printCycles(const std::vector<Cycle>& cycles){
	int i =0;
	for(Cycle c : cycles){
		std::cout<<i<<"  "<<c.toString()<<std::endl;
		++i;
	}
}

void printConnected(const std::vector<CyclesSet*>& connected){
	for(CyclesSet* c : connected){
		std::cout<<c->toString()<<std::endl;
	}
}

bool DistancesCreation_TEST(bool silentMode) {
	Problem p = Problem(Criteria(0,0,0), Node());
	p.addNode(Node(0,"",0,0,0));
	p.addNode(Node(0,"",3,4,0));

	p.generateDistances();
	std::vector<std::vector<unsigned short>> dist = p.getDistances();
	return dist[0][1] == 5;
}

bool RandomProblem_TEST(bool silentMode){
	ProblemGenParams params;
	params.maxDemand = 600;
	params.minDemand = 100;
	params.maxX = 1000;
	params.maxY = 1000;
	params.nodes = 20;

	Criteria c(1000,1000,5,500,0,2);

	Problem p = createRandomProblem(c, params);

	CycleCreator cc(p);
	cc.create();
	return true;
}

bool Problem5Nodes_TEST(bool silentMode){
	Problem p = problem5Nodes();
	CycleCreator cc(p);

	cc.create();
	std::vector<Cycle> cycles = cc.getCycles();

	if(!silentMode)
		printCycles(cycles);

	CycleConnector ccon(p, cycles);
	ccon.connect();

	std::vector<Solution> solutions = ccon.getSolutions();
	if(!silentMode){
		for(Solution sol : solutions){
			std::cout<<sol.toString();
		}
	}

	return 25 == cycles.size();
}

bool Problem6Nodes_TEST(bool silentMode){
	Problem p = problem6Nodes();
	CycleCreator cc(p);

	cc.create();
	std::vector<Cycle> cycles = cc.getCycles();

	if(!silentMode)
		printCycles(cycles);

	return 56 == cycles.size();
}

bool Problem10Nodes_TEST(bool silentMode){
	Problem p = problem10Nodes();
	CycleCreator cc(p);

	cc.create();
	std::vector<Cycle> cycles = cc.getCycles();

	//if(!silentMode)
		printCycles(cycles);

	CycleConnector ccon(p, cycles);
	std::vector<CyclesSet*> connected = ccon.connect();
	//if(!silentMode)
		printConnected(connected);

	std::vector<Solution> solutions = ccon.getSolutions();
	if(!silentMode){
		for(Solution sol : solutions){
			std::cout<<sol.toString();
		}
	}

	return 175 == cycles.size();
}


#endif /* TEST_PROBLEMTEST_H_ */
