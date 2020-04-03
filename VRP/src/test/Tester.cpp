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

Tester::Tester() {

  tests["PermutationsGeneration_TEST"] = &PermutationsGeneration_TEST;
  tests["CriteriaSerialization_TEST"]  = &CriteriaSerialization_TEST;
  tests["NodeSerialization_TEST"]      = &NodeSerialization_TEST;
  tests["CycleSerialization_TEST"]     = &CycleSerialization_TEST;
  tests["DistancesCreation_TEST"]      = &DistancesCreation_TEST;
  //tests["RandomProblem_TEST"]        = &RandomProblem_TEST; (too long)
  tests["Problem5Nodes_TEST"]          = &Problem5Nodes_TEST;
  tests["Problem6Nodes_TEST"]          = &Problem6Nodes_TEST;
  tests["Problem10Nodes_TEST"]         = &Problem10Nodes_TEST;
  tests["NodeDeserialization_TEST"]    = &NodeDeserialization_TEST;
  tests["ZDistanceMatrixReadingTest"]   = &DistanceMatrixReading_TEST;

  //tests["ZAnalyze_TEST"]               = &ZAnalyze_TEST;
  //tests["Problem20Nodes_TEST"]	   = &Problem20Nodes_TEST; (too long)
}

Tester::~Tester() {
  // TODO Auto-generated destructor stub
}

void Tester::runAll() {
  int failed = 0;
  int passed = 0;
  for (auto test : tests) {
    std::cout << test.first << ": STARTED" << std::endl;
    bool status = test.second();
    status ? passed++ : failed++;
    std::cout << test.first << ": " << (status ? "PASSED" : "FAILED") << std::endl;
  }
  std::cout << std::endl << "Tests summary:" << std::endl << passed << " tests passed, " << failed << " tests failed"
      << std::endl;
}

