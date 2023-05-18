package main

import "sort"

func threeSum(nums []int) [][]int {
	ret := make([][]int, 0)

	sort.Ints(nums)
	s := len(nums)

	b := 0
	for b < s && nums[b] <= 0 {
		b++
	}

	i := 0
	for i < b {

		j := i + 1
		for j < s {

			n := 0 - nums[i] - nums[j]
			idx := sort.SearchInts(nums, n+1) - 1
			if idx > j && idx < s && nums[idx] == n {
				ret = append(ret, []int{nums[i], nums[j], n})
			}

			// update j
			j++
			for j < s && nums[j] == nums[j-1] {
				j++
			}
		}

		// update i
		i++
		for i < b && nums[i] == nums[i-1] {
			i++
		}
	}

	return ret
}
