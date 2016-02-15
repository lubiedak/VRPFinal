/*
 * CriteriaDao.cpp
 *
 *  Created on: 15 Jan 2016
 *      Author: lubiedak
 */

#include "CriteriaDao.h"
#include <iostream>

uint16_t convertToInt(std::map<std::string, std::string>& params, std::string key) {
  uint16_t value = 0;
  try {
    value = (uint16_t) (std::stoi(params[key]));
  } catch (const std::out_of_range& e) {
    std::cout << " field " << key << " doesn't exist" << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << " field " << key << " is invalid" << std::endl;
  }
  return value;
}

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
  uint16_t n = convertToInt(values, "minNodes");
  uint16_t N = convertToInt(values, "maxNodes");
  uint16_t c = convertToInt(values, "minCapacity");
  uint16_t C = convertToInt(values, "maxCapacity");
  uint16_t d = convertToInt(values, "minDistance");
  uint16_t D = convertToInt(values, "maxDistance");
  criteria = Criteria(C, D, N, c, d, n);

  return true;
}

