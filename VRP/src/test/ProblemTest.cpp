/*
 * ProblemTest.cpp
 *
 *  Created on: 9 Jan 2016
 *      Author: lubiedak
 */

#include "../model/Problem.h"
#include "ProblemTest.h"

#include <iostream>
#include <string>

#include "../solver/CycleCreator.h"
#include "../solver/CycleConnector.h"
#include "../solver/Solution.h"
#include "resources/ProblemsForTest.h"


void printCycles(const std::vector<Cycle>& cycles){
	int i =0;
	for(Cycle c : cycles){
		std::cout<<i++<<"  "<<c.toString()<<std::endl;
	}
}

void printConnected(const std::vector<CyclesSet*>& connected){
	int i =0;
	for(CyclesSet* c : connected){
		std::cout<<i++<<"  "<<c->toString()<<std::endl;
	}
}

bool DistancesCreation_TEST(bool silentMode) {
	Problem p = Problem(Criteria(0,0,0), Node());
	p.addNode(Node(0,"",0,0,0));
	p.addNode(Node(0,"",3,4,0));

	p.generateDistances();
	std::vector<std::vector<unsigned short>> dist = p.getDistances();
	return dist[1][2] == 5;
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
	ccon.connect();
	/*
	//if(!silentMode)
		printConnected(connected);

	std::vector<Solution> solutions = ccon.getSolutions();
	if(!silentMode){
		for(Solution sol : solutions){
			std::cout<<sol.toString();
		}
	}*/

	return 175 == cycles.size();
}

bool Problem20Nodes_TEST(bool silentMode){
	Problem p = problem20Nodes();
	CycleCreator cc(p);

	cc.create();
	std::vector<Cycle> cycles = cc.getCycles();

	//if(!silentMode)
		printCycles(cycles);

	CycleConnector ccon(p, cycles);
	ccon.connect();


	std::vector<Solution> solutions = ccon.getSolutions();
	if(!silentMode){
		for(Solution sol : solutions){
			std::cout<<sol.toString();
		}
	}

	return 175 == cycles.size();
}

