package main

func fac(n int) uint {
	if n == 0 {
		return 1
	}
	var res uint = 1
	for i := 2; i <= n; i++ {
		res = res * uint(i)
	}
	return res
}
func uniquePaths(m int, n int) int {
	return int(fac(m+n-2) / (fac(m-1) * fac(n-1)))
}
