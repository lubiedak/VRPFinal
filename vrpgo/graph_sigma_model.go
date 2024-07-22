package main

import "strconv"

type NodeV struct {
	Key   		 string 		`json:"key"`
	Parameters   NodeAttributes `json:"attributes"`
}

type NodeAttributes struct {
	Key   string `json:"key"`
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

func toNodeV(node Node, color string, size int) NodeV {
	id := strconv.Itoa(node.id)
	return NodeV{Key: id, Parameters: NodeAttributes{Key: id, Label: id, X: node.x, Y: node.y, Size: size, Color: color}}
}