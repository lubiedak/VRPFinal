/*
 * Solution.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_SOLUTION_H_
#define SOLVER_SOLUTION_H_

#include <vector>

#include "../model/Cycle.h"
#include "../model/serialization/Serialized.h"
#include "CyclesSet.h"

class Solution: public Serialized {
public:

  Solution() {
  }

  Solution(CyclesSet& cs, const std::vector<Cycle>& cycles);
  virtual ~Solution();

  virtual std::string serialize();
  virtual bool deserialize(std::string);
  
  std::string toString();
  crow::json::wvalue toJson();
  crow::json::wvalue toJsonForDrawing();
  uint32_t getDistance() const {
    return distance;
  }
  uint32_t getDemand() const {
    return demand;
  }

private:
  uint32_t distance;
  uint32_t demand;
  std::vector<Cycle> optimizedCycles;
};

#endif /* SOLVER_SOLUTION_H_ */
