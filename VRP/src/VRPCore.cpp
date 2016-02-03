//============================================================================
// Name        : VRPCore.cpp
// Author      : lubiedak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "io/ArgParser.h"
#include "io/ProblemLoader.h"
#include "model/Criteria.h"
#include "model/Cycle.h"
#include "solver/CycleConnector.h"
#include "solver/CycleCreator.h"
#include "test/RandomProblemGenerator.h"

using namespace std;

void randomProblem(std::string dir);

int main(int argc, char** argv) {
	ArgParser argParser(argc, argv);

	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%d-%m-%Y", timeinfo);
	std::string timed(buffer);

	for (int i = 0; i < 500; ++i) {
		std::string dir = "sim2";
		dir += timed + "/";
		dir += to_string(i);
		dir += "/";
		std::string mkdir= "mkdir -p "+dir;
		system(mkdir.c_str());
		randomProblem(dir);

	}

	ProblemLoader p("../src/test/resources/problemExample.txt");
	Problem problem = p.load();
	std::cout << problem.toString();
	return 0;
}

void randomProblem(std::string dir) {
	ProblemGenParams params;
	params.maxDemand = 500;
	params.minDemand = 100;
	params.maxX = 1000;
	params.maxY = 1000;
	params.nodes = 20;

	Criteria c(1000, 1000, 5, 300, 0, 1);

	RandomProblemGenerator rpg(params, c);

	Problem p = rpg.generate();
	rpg.save(dir, "input");
	p.analyze();

	CycleCreator cc(p);

	cc.create();
	std::vector<Cycle> cycles = cc.getCycles();

	CycleConnector ccon(p, cycles);
	ccon.connect();

	Solution solution = ccon.getSolution();

	std::ofstream myfile;
	myfile.open((dir + "output").c_str());
	myfile << solution.toString();
	myfile.close();

	std::cout << solution.toString() << std::endl;
}
