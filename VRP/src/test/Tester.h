/*
 * Tester.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef TEST_TESTER_H_
#define TEST_TESTER_H_

class Tester {
public:
	Tester();
	virtual ~Tester();
	void runAll();

private:
	bool PermutationsGeneration_TEST();
};

#endif /* TEST_TESTER_H_ */
