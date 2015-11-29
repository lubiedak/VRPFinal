/*
 * Criteria.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "Criteria.h"
#include <sstream>


std::string Criteria::toString(){
	std::stringstream oss;
    oss<<std::string("class=Criteria")
	   <<std::string(",maxCapacity=") << maxCapacity
	   <<std::string(",minCapacity=") << minCapacity
	   <<std::string(",maxDistance=") << maxDistance
	   <<std::string(",minDistance=") << minDistance
	   <<std::string(",maxNodes=")    << maxNodes
	   <<std::string(",minNodes=")    << minNodes;
    return oss.str();
}

std::string Criteria::serialize(){

