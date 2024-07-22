package main

import "math/rand/v2"

func createNodes(n, size int) []Node {
	var nodes = make([]Node, n+1)

	nodes[0] = Node{id: 0, x: size / 2, y: size / 2}

	for i := 1; i < n+1; i++ {
		nodes[i] = Node{id: i, x: rand.IntN(size), y: rand.IntN(size)}
	}

	return nodes
}