/*
 * Tester.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Tester.h"

#include <iostream>
#include <utility>

#include "../model/Criteria.h"
#include "../solver/PermutationGen.h"

/**
 * These tests checks if permutation works correctly
 */
bool PermutationsGeneration_TEST(bool silentMode) {

	int base = 5;
	PermutationGen<int> permGen = PermutationGen<int>(base);
	permGen.setSilentMode(silentMode);
	permGen.Permute(base, base);

	//Assert
	return (permGen.getFullPermTable()[3][2] == 1
			&& permGen.getFullPermTable()[10][0] == 3);
}

bool SerializationModel_TEST(bool silentMode){
	Criteria cr = Criteria(1,2,3);
	std::string expectedCR = "class=Criteria,maxCapacity=1,minCapacity=0"
			",maxDistance=2,minDistance=0,maxNodes=3,minNodes=0";

	std::cout<<expectedCR<<std::endl;
	std::cout<<cr.toString()<<std::endl;

	return 0 == expectedCR.compare(cr.toString());
}


Tester::Tester(bool silentMode) {
	tests["PermutationsGeneration_TEST"] = &PermutationsGeneration_TEST;
	tests["SerializationModel_TEST"] = &SerializationModel_TEST;

	this->silentMode = silentMode;
}

Tester::~Tester() {
	// TODO Auto-generated destructor stub
}

void Tester::runAll() {
	for(auto test : tests){
		std::cout<<test.first<<": " << (test.second(silentMode) ? "PASSED":"FAILED")<<std::endl;
	}
}

