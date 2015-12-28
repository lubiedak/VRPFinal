/*
 * Tester.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Tester.h"

#include <iostream>
#include <utility>

#include "PermutationGen_test.h"
#include "SerializationTest.h"
#include "ProblemTest.h"


Tester::Tester(bool silentMode) {
	this->silentMode = silentMode;

	tests["PermutationsGeneration_TEST"] = &PermutationsGeneration_TEST;
	tests["CriteriaSerialization_TEST"]  = &CriteriaSerialization_TEST;
	tests["NodeSerialization_TEST"]      = &NodeSerialization_TEST;
	tests["CycleSerialization_TEST"]     = &CycleSerialization_TEST;
	tests["ProblemSerialization_TEST"]   = &ProblemSerialization_TEST;
	tests["SolutionSerialization_TEST"]  = &SolutionSerialization_TEST;
	tests["DistancesCreation_TEST"]      = &DistancesCreation_TEST;
	tests["RandomProblem_TEST"]          = &RandomProblem_TEST;
	tests["Problem5Nodes_TEST"]			 = &Problem5Nodes_TEST;
}

Tester::~Tester() {
	// TODO Auto-generated destructor stub
}

void Tester::runAll() {
	for(auto test : tests){
		std::cout<<test.first<<": ";
		std::cout<< (test.second(this->silentMode) ? "PASSED":"FAILED")<<std::endl;
	}
}

