package main

import (
	"encoding/json"
	"fmt"
	"math/bits"
)

func create(size, max_nodes int, nodes []Node) [] Cycle {
	last_possible_cycle := uint(1) << size
	distances := calculate_distances(nodes)
	for bitts := uint(1); bitts < last_possible_cycle; bitts++ {
		n := uint(bits.OnesCount(bitts))
		if(n <= uint(max_nodes)){
			nodeIds := nodesIds(bitts, n)
			fmt.Println(nodes)
			cycle := optimizeAndCreateCycle(bitts, nodeIds, distances)
			cycleJson, _ := json.Marshal(cycle)
			fmt.Println(string(cycleJson))

		} 
	}
	return nil
}

func nodesIds(bitts, n uint) []int {
	nodesIds := make([]int, n)
	i := 0
	for it := range(32){
		if(1 << it & bitts != 0){
			nodesIds[i] = it
			i++
		}
	}
	return nodesIds
}

func optimizeAndCreateCycle(idd uint, nodes []int, distances [][]int) Cycle {
	n := len(nodes)
	if(n > 2){
		minDistance := 99999
		bestRow := 0
		for row := 0 ; row < len(perms[n]); row++ {
			distance := distances[0][nodes[perms[n][row][0]]]
			for col := 0 ; col < len(perms[n][row]) - 1 ; col++ {
				distance += distances[nodes[perms[n][row][col]]][nodes[perms[n][row][col+1]]]
			}
			distance += distances[0][nodes[perms[n][row][n-1]]]

			if(distance < minDistance){
				minDistance = distance
				bestRow = row
			}
		}
		newNodes := make([]int, n)
		for i := range(n){
			newNodes[i] = nodes[perms[n][bestRow][i]]
		}
		return Cycle{id: idd, distance: minDistance, nodeIds: newNodes}
	}

	distance := 0
	if(n==1){
		distance = distances[0][nodes[0]] + distances[nodes[0]][0]
	}
	if(n==2){
		distance = distances[0][nodes[0]] + distances[nodes[0]][nodes[1]] + distances[nodes[1]][0]
	}

	return Cycle{id: idd, distance: distance, nodeIds: nodes}
}