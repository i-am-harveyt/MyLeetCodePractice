package main

func uniquePaths(m int, n int) int {
	ret := float64(1.0)

  n_f := float64(n-1)
  m_f := float64(m-1)
	for i := float64(1); i <= m_f; i++ {
		ret *= float64(n_f + i)
    ret /= i
	}

	return int(ret)
}
