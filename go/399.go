package main

import "sort"

type Pair struct {
	Node  string
	Value float64
}

func dfs(cur string, goal string, m map[string][]Pair) float64 {
	if _, ok := m[cur]; !ok {
		return -1
	} else if _, ok := m[goal]; !ok {
		return -1
	}
	if cur == goal {
		return 1
	}
	visited := make(map[string]bool)
	stack := []Pair{{cur, 1}}
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		visited[node.Node] = true
		if node.Node == goal {
			return node.Value
		}
		for _, neighbor := range m[node.Node] {
			if !visited[neighbor.Node] {
				stack = append(stack, Pair{neighbor.Node, node.Value * neighbor.Value})
			}
		}
	}
	return -1
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	// construct graph
	graph := make(map[string][]Pair)
	for i, edge := range equations {
		a, b := edge[0], edge[1]
		value := values[i]
		graph[a] = append(graph[a], Pair{b, value})
		graph[b] = append(graph[b], Pair{a, 1 / value})
	}
	// sort neighbors for each node
	for _, neighbors := range graph {
		sort.SliceStable(neighbors, func(i, j int) bool {
			return neighbors[i].Node < neighbors[j].Node
		})
	}
	// dfs
	ret := make([]float64, len(queries))
	for i, query := range queries {
		ret[i] = dfs(query[0], query[1], graph)
	}
	return ret
}
