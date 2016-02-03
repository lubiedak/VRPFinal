/*
 * RandomProblemGenerator.cpp
 *
 *  Created on: 22 Jan 2016
 *      Author: lubiedak
 */

#include "RandomProblemGenerator.h"

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

#include "../model/Node.h"

RandomProblemGenerator::RandomProblemGenerator(ProblemGenParams & params,
		Criteria& criteria) :
		params(params), criteria(criteria) {
	// TODO Auto-generated constructor stub

}

RandomProblemGenerator::~RandomProblemGenerator() {
	// TODO Auto-generated destructor stub
}

Problem RandomProblemGenerator::generate() {
	Problem p(criteria, Node(0, "Depot", 0, 0, 0));
	p.setCriteria(criteria);
	srand(time(NULL));
	for (uint16_t i = 1; i <= params.nodes; ++i) {
		Node n = Node(i, std::string("rand"), rand() % params.maxX,
				rand() % params.maxY,
				params.minDemand
						+ rand() % (params.maxDemand - params.minDemand));
		p.addNode(n);
	}

	p.generateDistances();

	problem = p;
	return problem;
}

void RandomProblemGenerator::save(std::string dir, std::string fileName) {

	std::ofstream myfile;
	myfile.open((dir + fileName).c_str());
	myfile << problem.toString();
	myfile.close();
}
