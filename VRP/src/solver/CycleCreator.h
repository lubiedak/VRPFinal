/*
 * CycleCreator.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_CYCLECREATOR_H_
#define SOLVER_CYCLECREATOR_H_

#include <stdint.h>
#include <vector>

#include "../model/Cycle.h"
#include "../model/Node.h"
#include "../model/Problem.h"
#include "PermutationGen.h"

class CycleCreator {
public:
  CycleCreator(const Problem& p);
  CycleCreator(const Problem& p, bool optimize);
  virtual ~CycleCreator();

  /**
   * Responsible for creating all optimised cycles
   * based on problem criteria
   */
  void create();

  const std::vector<Cycle>& getCycles() const {
    return cycles;
  }

private:
  PermutationGen<int> permGen;
  const Problem& problem;
  std::vector<Cycle> cycles;

  bool silentMode;
  bool optimizations;

  uint32_t countN();
  std::vector<uint32_t> countPossibleCycles();
  uint32_t NumberOfSetBits(int i);
  uint16_t SumDemand(uint32_t set, const std::vector<Node>& nodes);
  void analyzeCycles();
  void optimize();

  void removeFarSingleNodeCycles();
  void removeFarAndLowOnDemandDoubleNodesCycles();
  void removeSafe(uint32_t id);
};

#endif /* SOLVER_CYCLECREATOR_H_ */
