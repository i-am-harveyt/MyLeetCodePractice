package main

func canFinish(numCourses int, prerequisites [][]int) bool {

	graph := make([][]int, numCourses)
	for i := range graph {
		graph[i] = make([]int, 0)
	}

	indeg := make([]int, numCourses)
	for i := 0; i < len(prerequisites); i++ {
		graph[prerequisites[i][1]] = append(graph[prerequisites[i][1]], prerequisites[i][0])
		indeg[prerequisites[i][0]]++
	}

	deg0 := make([]int, 0)
	for i := 0; i < numCourses; i++ {
		if indeg[i] == 0 {
			deg0 = append(deg0, i)
		}
	}

	seq := make([]int, 0)
	for len(deg0) > 0 {
		seq = append(seq, deg0[0])
		for i := 0; i < len(graph[deg0[0]]); i++ {
			indeg[graph[deg0[0]][i]]--
			if indeg[graph[deg0[0]][i]] == 0 {
				deg0 = append(deg0, graph[deg0[0]][i])
			}
		}
		deg0 = deg0[1:]
	}

	return len(seq) == numCourses
}
