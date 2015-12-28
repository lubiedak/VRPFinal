/*
 * CyclesSet.h
 *
 *  Created on: 28 Dec 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_CYCLESSET_H_
#define SOLVER_CYCLESSET_H_

#include <cstdint>

class CyclesSet {
public:
	CyclesSet(uint32_t id, uint16_t distance, uint16_t firstElem, uint16_t size);
	virtual ~CyclesSet();

	uint32_t id;
	uint16_t distance;
	uint16_t *cycles;
};

#endif /* SOLVER_CYCLESSET_H_ */
