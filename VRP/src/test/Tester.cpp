/*
 * Tester.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Tester.h"
#include "../solver/PermutationGen.h"
#include <iostream>


bool PermutationsGeneration_TEST(bool silentMode) {

	PermutationGen<int> permGen = PermutationGen<int>(3);
	permGen.setSilentMode(silentMode);
	permGen.Permute(3, 3);

	//Assert
	return permGen.getFullPermTable()[3][2] == 1;
}

Tester::Tester(bool silentMode) {
	tests["PermutationsGeneration_TEST"] = &PermutationsGeneration_TEST;

	this->silentMode = silentMode;
}

Tester::~Tester() {
	// TODO Auto-generated destructor stub
}

void Tester::runAll() {
	for(auto test : tests){
		std::cout<<test.first<<": " << (test.second(silentMode) ? "PASSED":"FAILED");
	}
}

