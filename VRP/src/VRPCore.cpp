//============================================================================
// Name        : VRPCore.cpp
// Author      : lubiedak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

#include "model/Criteria.h"
#include "test/Tester.h"

using namespace std;


int main() {

	Tester tester(true);
	tester.runAll();

	return 0;
}

