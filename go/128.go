package main

import (
	"math"
)

func longestConsecutive(nums []int) int {
	var numSet map[int]int = make(map[int]int)
	for _, v := range nums {
		numSet[v]++
	}
	var ret int = 0
	for _, v := range nums {
		if numSet[v-1] == 0 {
			var tmp int = v + 1
			for numSet[tmp] > 0 { // if still in nums
				tmp++
			}
			ret = int(math.Max(float64(tmp)-float64(v), float64(ret)))
		}
	}
	return ret
}
