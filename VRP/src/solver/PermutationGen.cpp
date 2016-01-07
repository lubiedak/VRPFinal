/*
 * PermutationGen.cpp
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#include "PermutationGen.h"
#include <iostream>


template<typename T>
PermutationGen<T>::PermutationGen() {
	 silentMode = true;
}

template<typename T>
PermutationGen<T>::PermutationGen(int size) {
	this->base = std::vector<T>(size);
	this->perm = std::vector<T>(size);
	for(int i =0; i< size; ++i){
		base[i]=i;
		perm[i]=i;
	}
}

template<typename T>
PermutationGen<T>::PermutationGen(std::vector<T> base) {
	this->base = base;
	this->perm = base;
}

template<typename T>
PermutationGen<T>::~PermutationGen() {
	// TODO Auto-generated destructor stub
}

template<typename T>
void PermutationGen<T>::Swap(int a, int b) {
	T temp = perm[a];
	perm[a] = perm[b];
	perm[b] = temp;
}

template<typename T>
void PermutationGen<T>::Print(int size) {
	for (int i = 0; i < size; i++)
		std::cout << perm[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void PermutationGen<T>::Permute(int k, int size) {
	int i;
	if (k == 0){
		if(!silentMode)
			Print(size);

		fullPermTable.push_back(perm);
	}
	else {
		for (i = k - 1; i >= 0; i--) {
			Swap(i, k - 1);
			Permute(k - 1, size);
			Swap(i, k - 1);
		}
	}
}

template class PermutationGen<int>;
template class PermutationGen<short>;

