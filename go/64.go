package main

func minPathSum(grid [][]int) int {
	n := len(grid) + 1
	m := len(grid[0]) + 1
	mtx := make([][]int, n)
	for i := range mtx {
		mtx[i] = make([]int, m)
		for j := range mtx[i] {
			mtx[i][j] = 1<<31 - 1
		}
	}
	mtx[0][1] = 0
	mtx[1][0] = 0

	m--
	n--
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
      if mtx[i-1][j] < mtx[i][j-1] {
        mtx[i][j] = grid[i-1][j-1] + mtx[i-1][j]
      } else {
        mtx[i][j] = grid[i-1][j-1] + mtx[i][j-1]
      }

		}
	}

	return mtx[n][m]
}
