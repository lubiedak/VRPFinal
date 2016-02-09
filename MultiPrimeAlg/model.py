class Node:
	def __init__(self, i, x, y, d):
		self.id = i
		self.x  = x
		self.y  = y
		self.d  = d
	def toString(self):
		string = str(self.id) + " " + str(self.x) + " " + str(self.y) + " " + str(self.d)
		return string

class Edge:
	def __init__(self, a, b):
		self.a = a
		self.b = b

class Graph:
	def __init__(self):
		self.nodes = []
		self.edges = []
	def addNode(self, node):
		self.nodes.append(node)

	def addEdge(self, edge):
		self.edges.append(edge)

	def popNode(self, nodeId):
		for i in range(len(self.nodes)):
			if(self.nodes[i].id == nodeId):
				return self.nodes.pop(i)

	def toString(self):
		for node in self.nodes:
			print(node.toString())