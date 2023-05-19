package main

func findSmallestSetOfVertices(n int, edges [][]int) []int {
	ret := make([]int, 0)
	in := make([]bool, n)

	for _, edge := range edges {
		in[edge[1]] = true
	}
	for i := range in {
		if !in[i] {
			ret = append(ret, i)
		}
	}

	return ret
}
