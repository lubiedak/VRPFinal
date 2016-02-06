/*
 * CriteriaDao.cpp
 *
 *  Created on: 15 Jan 2016
 *      Author: lubiedak
 */

#include "CriteriaDao.h"

CriteriaDao::CriteriaDao(Criteria c) :
    criteria(c) {
  membersCount = 6;
}

CriteriaDao::~CriteriaDao() {
  // TODO Auto-generated destructor stub
}

std::string CriteriaDao::serialize() {
  return criteria.toString();
}

bool CriteriaDao::deserialize(std::string str) {
  std::map<std::string, std::string> values = parse(str);

  return true;
}
