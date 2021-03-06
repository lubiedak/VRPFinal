/*
 * Tester.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef TEST_TESTER_H_
#define TEST_TESTER_H_

#include <map>
#include <string>

class Tester {
public:
  Tester();
  virtual ~Tester();
  void runAll();

private:
  std::map<std::string, bool (*)()> tests;
};

#endif /* TEST_TESTER_H_ */
