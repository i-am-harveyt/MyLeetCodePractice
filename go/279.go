package main

/*
 * This code can run but not work well
 * I still need some math analysis
 */
/* Recursive
func dp(n int, m map[int]int) int {
	if n == 0 {
		return 0
	} else if n == 1 {
		return 1
	} else if _, ok := m[n]; ok {
		return m[n]
	}
	m[n] = n
	for i := 2; i*i <= n; i++ {
		val := dp(n-i*i, m)
		if val < m[n] {
			m[n] = val
		}
	}
	m[n]++
	return m[n]
}

func numSquares(n int) int {
	return dp(n, make(map[int]int))
}
*/

/* Iterative */
func numSquares(n int) int {
	dp := make([]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = i
	}

	for i := 1; i <= n; i++ {
		for j := 1; j*j <= i; j++ {
			if dp[i-j*j]+1 < dp[i] {
				dp[i] = dp[i-j*j] + 1
			}
		}
	}

	return dp[n]
}
