package main

import (
	"strconv"
)

const graph_map_size int = 500

func randExample(n int) GraphV {
	var nodes = createNodesVisual(createNodes(n, graph_map_size))

	var edges = createEdgesVisual()

	graph := GraphV{Nodes: nodes, Edges: edges}

	return graph
}

func createNodesVisual(nodes []Node) []NodeV {
	var nodesV = make([]NodeV, len(nodes))

	nodesV[0] = NodeV{Key: "D", Parameters: NodeAttributes{Key: "D", Label: "Depot", X: nodes[0].x, Y: nodes[0].y, Size: 10, Color: "red"}}

	for i := 1; i < len(nodes); i++ {
        nodesV[i] = toNodeV(nodes[i], "black", 5)
    }
	return nodesV
}

func createEdgesVisual() []EdgeV {
	var edges = make([]EdgeV, 5)
	edges[0] = EdgeV{Id: strconv.Itoa(0), From: "D", To: "1"}
	for i := 1; i < 4; i++ {
        edges[i] = EdgeV{Id: strconv.Itoa(i), From: strconv.Itoa(i), To: strconv.Itoa(i+1)}
    }
	edges[4] = EdgeV{Id: strconv.Itoa(4), From: "4", To: "D"}
	return edges;
}
