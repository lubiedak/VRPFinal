package main

type Node struct {
	id uint32
	x  uint16
	y  uint16
}

func newNode(id uint32, x, y uint16) *Node {
	return &Node{id: id, x: x, y: y}
}

type Cycle struct {
	id       uint32
	distance uint32

	nodes []Node
}
