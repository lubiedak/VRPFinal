import numpy as np
import math as m
import random as r

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
    self.nodeA = a
    self.nodeB = b
    self.countDistance()
  def getLine(self):
    line = []
    line.append((self.nodeA.x, self.nodeB.x))
    line.append((self.nodeA.y, self.nodeB.y))
    return line
  def countDistance(self):
    dx = self.nodeA.x - self.nodeB.x
    dy = self.nodeA.y - self.nodeB.y
    self.distance = m.sqrt(dx*dx + dy*dy)

class Graph:
  def __init__(self):
    self.nodes = []
    self.edges = []
    self.middle = Node(-1,0,0,0)

  def addNode(self, node):
    self.nodes.append(node)

  def addEdge(self, edge):
    self.edges.append(edge)

  def popNode(self, nodeId):
    for i in range(len(self.nodes)):
      if(self.nodes[i].id == nodeId):
        return self.nodes.pop(i)

  def popRandNode(self):
    i = r.randint(0,len(self.nodes))
    return self.nodes.pop(i)
    
  def getNode(self, nodeId):
    for i in range(len(self.nodes)):
      if(self.nodes[i].id == nodeId):
        return self.nodes[i]

  def printNodes(self):
    for node in self.nodes:
      print(node.toString())

  def countDistances(self):
    # we assume that nodes are sorted by id, and there are no gaps
    self.distances = np.ndarray(shape=(len(self.nodes),len(self.nodes)), dtype=float, order='F')
    for i in range(len(self.nodes)):
      for j in range(len(self.nodes)):
        dx = self.nodes[i].x - self.nodes[j].x
        dy = self.nodes[i].y - self.nodes[j].y
        self.distances[i][j] = m.sqrt(dx*dx + dy*dy)

  def findMiddlePoint(self):
    x = 0
    y = 0
    size = len(self.nodes)
    for n in self.nodes:
      x+=n.x
      y+=n.y
    self.middle.x = x/size
    self.middle.y = y/size
    return self.middle


  def getSmartNodeIter(self, tree):
    middleTreeNode = tree.findMiddlePoint()
    self.findMiddlePoint()
    maxDistRatio = 0.0
    smartestNode = self.nodes[0]
    for n in self.nodes:
      edgeTree = Edge(middleTreeNode, n)
      edgeSelf = Edge(self.middle, n)
      distanceRatio = edgeSelf.distance/edgeTree.distance
      if(maxDistRatio<distanceRatio):
        smartestNode = n
        maxDistRatio = distanceRatio
    return smartestNode