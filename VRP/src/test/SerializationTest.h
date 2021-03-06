/*
 * SerializationTest.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include <iostream>
#include <string>

#include "../model/Criteria.h"
#include "../model/Cycle.h"
#include "../model/Node.h"
#include "../model/serialization/CriteriaDao.h"

bool CriteriaSerialization_TEST() {
  Criteria cr = Criteria(1, 2, 3);
  std::string expectedCR = "class=Criteria"
      ",maxCapacity=1,maxDistance=2,maxNodes=3"
      ",minCapacity=0,minDistance=0,minNodes=0";

  CriteriaDao crDao(cr);
  return 0 == expectedCR.compare(crDao.serialize());
}

bool CycleSerialization_TEST() {
  Cycle c;
  std::string expectedC = "class=Cycle,id=0,distance=0,demand=0";
  return 0 == expectedC.compare(c.serialize());
}

bool NodeSerialization_TEST() {
  Node n;
  std::string expectedN = "class=Node,id=0,name=node,x=0,y=0,demand=0";
  return 0 == expectedN.compare(n.serialize());
}

bool NodeDeserialization_TEST() {
  Node n(13, "xyz", 10, 20, 30);
  std::string expectedN = n.serialize();
  Node n2;
  n2.deserialize(expectedN);

  return n2 == n;
}

