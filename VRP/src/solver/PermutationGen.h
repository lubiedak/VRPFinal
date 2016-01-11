/*
 * PermutationGen.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef SOLVER_PERMUTATIONGEN_H_
#define SOLVER_PERMUTATIONGEN_H_

#include <vector>

template <typename T>
class PermutationGen {
public:
	PermutationGen();
	PermutationGen(int size);
	PermutationGen(std::vector<T> base);
	virtual ~PermutationGen();

	void Permute(int k, int size);

	void setSilentMode(bool silentMode) {
		this->silentMode = silentMode;
	}

	const std::vector<std::vector<T> >& getFullPermTable() const {
		return fullPermTable;
	}

private:
	void Swap(int a, int b);
	void Print(int size);

	std::vector<T> base;
	std::vector<T> perm;
	std::vector< std::vector<T> > fullPermTable;

	bool silentMode;
};

#endif /* SOLVER_PERMUTATIONGEN_H_ */
