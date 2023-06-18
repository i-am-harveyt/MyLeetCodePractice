
var MOD int = 1e9 + 7

func helper(memo *map[[2]int]int, grid *[][]int, r, c, prev int) int {

	key := [2]int{r, c}

	if r < 0 || c < 0 || r == len(*grid) || c == len((*grid)[0]) {
		return 0 // beyond scope
	} else if (*grid)[r][c] <= prev {
		return 0 // not strictly increasing
	} else if v, found := (*memo)[key]; found {
		return v
	}

	(*memo)[key] = ((((1+helper(memo, grid, r, c+1, (*grid)[r][c]))%MOD+
		helper(memo, grid, r, c-1, (*grid)[r][c]))%MOD+
		helper(memo, grid, r+1, c, (*grid)[r][c]))%MOD +
		helper(memo, grid, r-1, c, (*grid)[r][c])) % MOD

	return (*memo)[key]
}

func countPaths(grid [][]int) int {
	ret, memo := 0, make(map[[2]int]int, 0)
	for i := range grid {
		for j := range grid[0] {
			ret = (ret + helper(&memo, &grid, i, j, 0)) % MOD
		}
	}
	return ret
}
