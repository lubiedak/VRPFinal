/*
 * SerializationTest.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "../model/Criteria.h"
#include "../model/Cycle.h"

bool CriteriaSerialization_TEST(bool silentMode) {
	Criteria cr = Criteria(1, 2, 3);
	std::string expectedCR = "class=Criteria"
			",maxCapacity=1,maxDistance=2,maxNodes=3"
			",minCapacity=0,minDistance=0,minNodes=0";

	if (!silentMode) {
		std::cout << expectedCR << std::endl;
		std::cout << cr.serialize() << std::endl;
	}
	return 0 == expectedCR.compare(cr.serialize());
}

bool CycleSerialization_TEST(bool silentMode) {
	Cycle c;
	std::string expectedC = "class=Cycle,id=0,distance=0,demand=0";
	if (!silentMode) {
		std::cout << expectedC << std::endl;
		std::cout << c.serialize() << std::endl;
	}
	return 0 == expectedC.compare(c.serialize());
}

bool NodeSerialization_TEST(bool silentMode) {
	Node n;
	std::string expectedN = "class=Node,id=0,name=node,x=0,y=0,demand=0";
	if (!silentMode) {
		std::cout << expectedN << std::endl;
		std::cout << n.serialize() << std::endl;
	}
	return 0 == expectedN.compare(n.serialize());
}

bool NodeDeserialization_TEST(bool silentMode) {
	Node n(13, "xyz", 10, 20, 30);
	std::string expectedN = n.serialize();
	Node n2;
	n2.deserialize(expectedN);

	return n2 == n;
}


bool SolutionSerialization_TEST(bool silentMode) {
	return true;
}

bool ProblemSerialization_TEST(bool silentMode) {
	return true;
}

