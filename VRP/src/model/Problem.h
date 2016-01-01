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
	Problem(Criteria criteria, Node depot);
	Problem(Criteria criteria, Node depot, std::vector<Node> nodes);
	Problem(Criteria criteria, Node depot, std::vector<Node> nodes,
			std::vector< std::vector<uint16_t> > distances);
	virtual ~Problem(){};
	void generateDistances();
	void analyze();
	uint16_t approxCyclesCount() const;

	void setCriteria(const Criteria& criteria) {this->criteria = criteria;}

	const std::vector<Cycle>& getCycles() const {return cycles;}

	const std::vector<std::vector<uint16_t> >& getDistances() const {return distances;}
	void setDistances(const std::vector<std::vector<unsigned short> >& distances) {this->distances = distances;}

	const std::vector<Node>& getNodes() const {return nodes;}
	std::vector<Node> getNodesAndDepot(uint32_t) const;
	void setNodes(const std::vector<Node>& nodes) {this->nodes = nodes;}
	void addNode(const Node& node){nodes.push_back(node);}
	void setDepot(const Node& node){depot = node;}

	uint32_t size() const { return nodes.size(); }
	uint16_t getBiggestDemander() const {return biggestDemander;}

	uint16_t getMaxNodes() const {return criteria.maxNodes();}
	uint16_t getMinNodes() const {return criteria.minNodes();}
	uint16_t getMaxCapacity() const {return criteria.maxCapacity();}
	uint16_t getMinCapacity() const {return criteria.minCapacity();}
	uint16_t getMaxDistance() const {return criteria.maxDistance();}
	uint16_t getMinDistance() const {return criteria.minDistance();}

	uint16_t estimateConnectionsNeeded() const;

private:

	uint16_t findBiggestDemander();
	uint16_t sumDemands();
	bool checkProblemCorrectness();

	uint16_t biggestDemander;
	uint16_t demandsSum;

	Criteria criteria;
	Node depot;
	std::vector<Node> nodes;
	std::vector< std::vector<uint16_t> > distances;
	std::vector<Cycle> cycles;
};

#endif /* MODEL_PROBLEM_H_ */
