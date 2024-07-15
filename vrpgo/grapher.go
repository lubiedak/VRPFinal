package main

import (
	"encoding/json"
	"fmt"
	"strconv"
)

type NodeV struct {
	Id    string `json:"id"`
	Label string `json:"label"`
	X     int    `json:"x"`
	Y     int    `json:"y"`
	Size  int    `json:"size"`
	Color string `json:"color"`
}

type EdgeV struct {
	Id   string `json:"id"`
	From string `json:"source"`
	To   string `json:"target"`
}

type GraphV struct {
	Nodes []NodeV `json:"nodes"`
	Edges []EdgeV `json:"edges"`
}

func toNodeV(node *Node, color string, size int) NodeV {
	id := strconv.FormatUint(uint64(node.id), 10) // conversion from uint to string
	return NodeV{Id: id, Label: id, X: int(node.x), Y: int(node.y), Size: size, Color: color}
}

func exportExample() {
	n1 := toNodeV(newNode(1, 200, 200), "black", 10)
	n2 := toNodeV(newNode(2, 300, 400), "black", 10)
	e := EdgeV{Id: "1", From: "1", To: "2"}

	graph := GraphV{Nodes: []NodeV{n1, n2}, Edges: []EdgeV{e}}

	graphJson, _ := json.Marshal(graph)
	fmt.Println(string(graphJson))
}
