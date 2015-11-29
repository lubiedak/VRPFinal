/*
 * Criteria_test.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "../solver/PermutationGen.h"



/**
 * This test checks if permutation works correctly
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
