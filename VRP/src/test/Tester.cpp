/*
 * Tester.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Tester.h"

#include <iostream>
#include <utility>

#include "Criteria_test.h"
#include "PermutationGen_test.h"


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

