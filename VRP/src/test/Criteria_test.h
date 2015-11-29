/*
 * Criteria_test.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "../model/Criteria.h"

bool SerializationModel_TEST(bool silentMode){
	Criteria cr = Criteria(1,2,3);
	std::string expectedCR = "class=Criteria,maxCapacity=1,minCapacity=0"
			",maxDistance=2,minDistance=0,maxNodes=3,minNodes=0";

	std::cout<<expectedCR<<std::endl;
	std::cout<<cr.toString()<<std::endl;

	return 0 == expectedCR.compare(cr.toString());
}

