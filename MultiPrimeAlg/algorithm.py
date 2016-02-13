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

def createTrees(n, g):
  main = gg.generateGraph(n)
  trees = []
  for i in range(g):
    trees.append(m.Graph())

  for tree in trees:
    size = len(main.nodes)
    tree.addNode(main.popNode(r.randint(0,size)))


  while(len(main.nodes)>0):
    for tree in trees:
      (idT,idM) = findClosest(tree,main)
      node = main.popNode(idM)
      edge = m.Edge(tree.getNode(idT), node)
      tree.addNode(node)
      tree.addEdge(edge)



  for tree in trees:
    print("Tree")
    tree.printNodes()
  
  return trees

createTrees(10,2)