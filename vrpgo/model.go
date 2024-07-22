package main

type Node struct {
	id int
	x  int
	y  int
}

func newNode(id int, x, y int) *Node {
	return &Node{id: id, x: x, y: y}
}

type Cycle struct {
	id       uint
	distance int

	nodeIds []int
}
