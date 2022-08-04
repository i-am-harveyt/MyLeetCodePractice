package main

func nCm(n float64, m float64) int {
	var ret float64 = 1
	var i float64
	for i = 0; i < m; i++ {
		ret *= (n - i)
		ret /= (i + 1)
	}
	return int(ret)

}

func numTrees(n int) int {
	return nCm(float64(2*n), float64(n)) / (n + 1)
}
