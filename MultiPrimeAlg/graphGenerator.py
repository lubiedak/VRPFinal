import model as m
import random as r

maxX = 1000
maxY = 1000
maxD = 400

def generateGraph(n):
	graph = m.Graph()
	for i in range(n):
		node = m.Node(i, r.randint(0,maxX), r.randint(0,maxY), r.randint(0,maxD))
		graph.addNode(node)
	return graph



graph = generateGraph(10)
graph.toString()

node = graph.popNode(6)
graph.toString()
print(node.toString())