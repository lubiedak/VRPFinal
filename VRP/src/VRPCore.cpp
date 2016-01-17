//============================================================================
// Name        : VRPCore.cpp
// Author      : lubiedak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "io/ArgParser.h"
#include "io/ProblemLoader.h"
#include "test/ProblemTest.h"

using namespace std;

void randomProblem(int n);

int main(int argc, char** argv) {
	ArgParser argParser(argc, argv);
	//if ( argParser.parse() )
	//randomProblem(10);
	{
		//Tester tester(true);
		//tester.runAll();
	}


	ProblemLoader p("../src/test/resources/problemExample.txt");
	Problem problem = p.load();
	std::cout<<problem.toString();
	return 0;
}

void randomProblem(int n) {
	for (int i = 0; i < n; ++i) {
		RandomProblem_TEST(false);
	}
}
