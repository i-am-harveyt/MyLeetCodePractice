package main

func dfs(cur int, left bool, graph *[][]int, side *[]int) bool {
	if left {
		if (*side)[cur] == 1 {
			return true
		} else if (*side)[cur] == -1 {
			return false
		}
	} else if !left {
		if (*side)[cur] == -1 {
			return true
		} else if (*side)[cur] == 1 {
			return false
		}
	}
	if left {
		(*side)[cur] = 1
	} else {
		(*side)[cur] = -1
	}
	for _, v := range (*graph)[cur] {
		if !dfs(v, !left, graph, side) {
			return false
		}
	}
	return true
}

func isBipartite(graph [][]int) bool {
	side := make([]int, len(graph))
	for i := range graph {
		if side[i] == 0 {
			if !dfs(i, true, &graph, &side) {
				return false
			}
		}
	}
	return true
}
