/*
 * Problem.h
 *
 *  Created on: 28 Nov 2015
 *      Author: lubiedak
 */

#ifndef MODEL_PROBLEM_H_
#define MODEL_PROBLEM_H_

#include <vector>

#include "Criteria.h"
#include "Node.h"
#include "Cycle.h"

class Problem {
public:
	Problem();
	virtual ~Problem();
	void generateDistances();
	void analyze();

	const Criteria& getCriteria() const {return criteria;}
	void setCriteria(const Criteria& criteria) {this->criteria = criteria;}
	const std::vector<Cycle>& getCycles() const {return cycles;}
	void setCycles(const std::vector<Cycle>& cycles) {this->cycles = cycles;}
	const std::vector<std::vector<unsigned short> >& getDistances() const {return distances;}
	void setDistances(const std::vector<std::vector<unsigned short> >& distances) {this->distances = distances;}
	const std::vector<Node>& getNodes() const {return nodes;}
	void setNodes(const std::vector<Node>& nodes) {this->nodes = nodes;}
	void addNode(const Node& node){nodes.push_back(node);}

private:

	unsigned findBiggestDemander();
	unsigned sumDemands();

	unsigned biggestDemander;
	unsigned demandsSum;

	Criteria criteria;
	std::vector<Node> nodes;
	std::vector<Cycle> cycles;
	std::vector< std::vector<unsigned short> > distances;
};

#endif /* MODEL_PROBLEM_H_ */
