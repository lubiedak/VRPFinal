import algorithm as a
import matplotlib.pyplot as plt

#number of nodes
n = 100
#number of trees
t = 5

trees = a.createTreesIteratively(n,t)
#trees = a.createTreesSimultaneously(n,t)

styles = ['k-o', 'b-o', 'g-o', 'r-o', 'c-o']

for i in range(len(trees)):
  lines = []
  for edge in trees[i].edges:
    line = edge.getLine()
    plt.plot(line[0], line[1], styles[i%len(styles)], lw=2)

plt.show()