import model as m
import graphGenerator as gg


n = 100 #number of nodes

Graph main = gg.generateGraph(n)

g = 5  #number of trees

trees = []
for i in range(g):
  trees.append(Graph())

