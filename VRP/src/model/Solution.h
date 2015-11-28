/*
 * Solution.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef MODEL_SOLUTION_H_
#define MODEL_SOLUTION_H_

class Solution {
public:
	Solution();
	virtual ~Solution();

private:
	int some_info;
	std::vector<Cycle> optimizedCycles;
};

#endif /* MODEL_SOLUTION_H_ */
