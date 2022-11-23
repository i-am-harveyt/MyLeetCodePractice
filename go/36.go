package main

func validSquare(board [][]byte, x int, y int) bool {
	freq := make(map[byte]int)
	for i := y - 1; i <= y+1; i++ {
		for j := x - 1; j <= x+1; j++ {
			if board[i][j] != byte('.') {
				freq[board[i][j]]++
				if freq[board[i][j]] > 1 {
					return false
				}
			}
		}
	}
	return true
}

func validRow(board [][]byte, y int) bool {
	freq := make(map[byte]int)
	for i := 0; i < 9; i++ {
		if board[y][i] != byte('.') {
			freq[board[y][i]]++
			if freq[board[y][i]] > 1 {
				return false
			}
		}
	}
	return true
}

func validCol(board [][]byte, x int) bool {
	freq := make(map[byte]int)
	for i := 0; i < 9; i++ {
		if board[i][x] != byte('.') {
			freq[board[i][x]]++
			if freq[board[i][x]] > 1 {
				return false
			}
		}
	}
	return true
}

func isValidSudoku(board [][]byte) bool {
	x, y := 1, 1

	// for square
	for i := 0; i <= 2; i++ {
		for j := 0; j <= 2; j++ {
			if !validSquare(board, x+3*i, y+3*j) {
				return false
			}
		}
	}

	// for col & row
	for i := 0; i < 9; i++ {
		if !validCol(board, i) {
			return false
		}
	}
  for i := 0; i < 9; i++ {
		if !validRow(board, i) {
			return false
		}
	}

	return true
}
