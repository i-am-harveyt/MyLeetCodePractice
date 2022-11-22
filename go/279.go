package main

/* 
 * This code can run but not work well
 * I still need some math analysis
 */
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
