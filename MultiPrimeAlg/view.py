import algorithm as a
import matplotlib.pyplot as plt

trees = a.createTrees(100,1)

styles = ['k-o', 'b-o', 'g-o', 'r-o', 'c-o']

for i in range(len(trees)):
  lines = []
  for edge in trees[i].edges:
    line = edge.getLine()
    plt.plot(line[0], line[1], styles[i], lw=2)

plt.show()