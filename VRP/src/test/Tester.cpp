/*
 * Tester.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Tester.h"
#include "../solver/PermutationGen.h"

Tester::Tester() {
	// TODO Auto-generated constructor stub

}

Tester::~Tester() {
	// TODO Auto-generated destructor stub
}


void Tester::runAll() {

	PermutationsGeneration_TEST();

}

bool Tester::PermutationsGeneration_TEST() {

	PermutationGen<int> permGen = PermutationGen<int>(3);
	permGen.Permute(3,3);

	return true;
}
