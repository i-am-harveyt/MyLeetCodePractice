package main

func findJudge(n int, trust [][]int) int {
	arr := make([]int, n+1)

	for i := 0; i < len(trust); i++ {
		arr[trust[i][0]] = trust[i][1]
		arr[trust[i][1]]--
	}

	threshold := -(n - 1)
	for i := 1; i <= n; i++ {
		if arr[i] == threshold {
			return i
		}
	}

	return -1
}
