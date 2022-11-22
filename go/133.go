package main

// Definition for a Node.
type Node struct {
	Val       int
	Neighbors []*Node
}

func clone(mem map[int]*Node, n *Node) *Node {
	if n == nil {
		return nil
	}
	if _, ok := mem[n.Val]; !ok {
		mem[n.Val] = &Node{n.Val, make([]*Node, len(n.Neighbors))}
		for i := 0; i < len(n.Neighbors); i++ {
			mem[n.Val].Neighbors[i] = clone(mem, n.Neighbors[i])
		}
	}
	return mem[n.Val]
}

func cloneGraph(node *Node) *Node {
	mem := make(map[int]*Node, 100)
	return clone(mem, node)
}
