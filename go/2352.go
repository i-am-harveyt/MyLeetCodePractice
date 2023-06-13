package main

import (
	"strconv"
	"strings"
)

func equalPairs(grid [][]int) int {
	seen := make(map[string]int)

	// use string as key, store the frequency
	for _, arr := range grid {
		strSlice := make([]string, len(grid))
		for i, v := range arr {
			strSlice[i] = strconv.Itoa(v)
		}
		seen[strings.Join(strSlice, ",")] += 1
	}

	ret := 0

	// check if string existed, add frequency
	for i := range grid {
		strSlice := make([]string, len(grid))
		for j := range grid {
			strSlice[j] = strconv.Itoa(grid[j][i])
		}
		if v, found := seen[strings.Join(strSlice, ",")]; found {
			ret += v
		}
	}

	return ret
}
