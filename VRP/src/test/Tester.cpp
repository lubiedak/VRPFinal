/*
 * Tester.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Tester.h"
#include "../solver/PermutationGen.h"
#include <iostream>

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

