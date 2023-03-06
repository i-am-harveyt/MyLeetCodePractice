package main

func rotate(nums []int, k int) {
  k %= len(nums)
	tmp, s := make([]int, len(nums)), len(nums)
	copy(tmp, nums)
	for i := 0; i < s; i++ {
		nums[k] = tmp[i]
		k = (k + 1) % s
	}
}
