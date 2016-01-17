//============================================================================
// Name        : VRPCore.cpp
// Author      : lubiedak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

#include "io/ArgParser.h"
#include "model/Criteria.h"
#include "test/Tester.h"
#include "test/ProblemTest.h"

using namespace std;

void randomProblem(int n);

int main(int argc, char** argv) {
	ArgParser argParser(argc, argv);
	//if ( argParser.parse() )
	randomProblem(10);
	{
		//Tester tester(true);
		//tester.runAll();
	}
	return 0;
}

void randomProblem(int n) {
	for (int i = 0; i < n; ++i) {
		RandomProblem_TEST(false);
	}
}
