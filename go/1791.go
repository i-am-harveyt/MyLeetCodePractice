package main

func findCenter(edges [][]int) int {
	n := 0
	for i := 0; i < len(edges); i++ {
		if edges[i][0] > n {
			n = edges[i][0]
		}
		if edges[i][1] > n {
			n = edges[i][1]
		}
	}

	arr := make([]int, n+1)
	for i := 0; i < len(edges); i++ {
		arr[edges[i][0]]++
		arr[edges[i][1]]++
	}

	t := n - 1
	for i := 1; i <= len(arr); i++ {
		if arr[i] == t {
			return i
		}
	}

	return -1
}
