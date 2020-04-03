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
bool PermutationsGeneration_TEST() {
  int base = 5;
  PermutationGen<int> permGen = PermutationGen<int>(base);
  permGen.Permute(base, base);

  return (permGen.getFullPermTable()[3][2] == 1 && permGen.getFullPermTable()[10][0] == 3);
}
