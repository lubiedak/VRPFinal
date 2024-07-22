package main

import "math"

func calculate_distances(nodes []Node) [][]int {
	distances := make([][]int, len(nodes))
	for i := range len(nodes) {
		distances[i] = make([]int, len(nodes))
		for j := range len(nodes) {
			distances[i][j] = int(math.Sqrt(math.Pow(float64(nodes[i].x-nodes[j].x), 2) + math.Pow(float64(nodes[i].y-nodes[j].y), 2)))
		}
	}
	return distances
}