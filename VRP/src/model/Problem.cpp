/*
 * Problem.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Problem.h"

Problem::Problem() {
	// TODO Auto-generated constructor stub

}

Problem::~Problem() {
	// TODO Auto-generated destructor stub
}

void Problem::analyze() {
	biggestDemander = findBiggestDemander();
	demandsSum = sumDemands();
}

unsigned Problem::findBiggestDemander() {
	unsigned bigDemand = 0;
	unsigned demander = 0;
	for(unsigned i = 0; i<nodes.size(); ++i){
		if(nodes[i].getDemand() > bigDemand){
			bigDemand =nodes[i].getDemand();
			demander = i;
		}
	}
	return demander;
}

unsigned Problem::sumDemands() {
	unsigned demand = 0;
	for(unsigned i = 0; i<nodes.size(); ++i){
		demand+=nodes[i].getDemand();
	}
	return demand;
}
