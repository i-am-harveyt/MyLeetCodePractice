package main

func getMaximumGenerated(n int) int {
	if n == 0 {
		return 0
	}

	n += 1
	var ret int = 1
	var mem []int = make([]int, n)
  mem[1] = 1
	for i := 2; i < n; i++ {

		if i%2 == 1 {
			mem[i] = mem[i/2] + mem[i/2+1]
		} else {
			mem[i] = mem[i/2]
		}

		if mem[i] > ret {
			ret = mem[i]
		}
	}

	return ret
}
