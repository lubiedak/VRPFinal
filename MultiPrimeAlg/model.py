class Node:
	def __init__(self, x, y):
		self.x = x
		self.y = y

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
