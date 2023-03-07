package main

func findKthPositive(arr []int, k int) int {
	cnt, cur := 0, 0
	for _, v := range arr {
		for v > cur+1 {
			cnt, cur = cnt+1, cur+1
			if cnt == k {
				return cur
			}
		}
		cur++
	}
	return cur + k - cnt
}
