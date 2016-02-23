/*
 * CyclesSet.h
 *
 *  Created on: 28 Dec 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_CYCLESSET_H_
#define SOLVER_CYCLESSET_H_

#include <cstdint>
#include <string>
#include <vector>

#include "../model/Cycle.h"

class CyclesSet {
public:
  CyclesSet();
  CyclesSet(const Cycle& cycle, uint16_t firstElem, uint16_t size);
  CyclesSet(uint32_t id, uint16_t distance, uint16_t size);
  virtual ~CyclesSet();

  std::string toString();

  uint32_t id;
  uint16_t distance;
  uint16_t size;
  std::vector<uint16_t> cycles;
};

#endif /* SOLVER_CYCLESSET_H_ */
