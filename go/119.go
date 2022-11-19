package main

func getRow(rowIndex int) []int {
	mat := make([][]int, 0)

  var size int = rowIndex + 1
	for i := 0; i < size; i++ {
		tmp := make([]int, i+1)
		tmp[0] = 1
		tmp[i] = 1
		for j := 1; j < i; j++ {
			tmp[j] = mat[i-1][j-1] + mat[i-1][j]
		}
    mat = append(mat, tmp)
	}

	return mat[rowIndex]
}
