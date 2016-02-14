import model as m
import graphGenerator as gg
import random as r


def findClosest(tree, main):
  minDistance = 1500
  idM = 0
  idT = 0
  for nodeT in tree.nodes:
    for nodeM in main.nodes:
      dist = main.distances[nodeT.id][nodeM.id]
      if(dist < minDistance):
        minDistance = dist
        idM = nodeM.id
        idT = nodeT.id
  return (idT, idM)

def addClosestNodeToTree(tree, main):
  (idT,idM) = findClosest(tree,main)
  node = main.popNode(idM)
  edge = m.Edge(tree.getNode(idT), node)
  tree.addNode(node)
  tree.addEdge(edge)

def initTrees(n,t):
  main = gg.generateGraph(n)
  trees = []
  for i in range(t):
    trees.append(m.Graph())
  return (main, trees)

def createTreesIteratively(n, t):
  (main, trees) = initTrees(n,t)
  size = len(main.nodes)
  for tree in trees:
    tree.addNode(main.popRandNode())
    i = 1
    while(i<n/t):
      addClosestNodeToTree(tree, main)
      i+=1
  return trees

def createTreesSimultaneously(n, t):
  (main, trees) = initTrees(n,t)
  size = len(main.nodes)
  for tree in trees:
    tree.addNode(main.popRandNode())

  while(len(main.nodes)>0):
    for tree in trees:
      addClosestNodeToTree(tree, main)
  return trees