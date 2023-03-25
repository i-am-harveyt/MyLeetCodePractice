package main

func find(n int, set *[]int) int {
	if (*set)[n] < 0 {
		return n
	}
	(*set)[n] = find((*set)[n], set)
	return (*set)[n]
}

func union(p int, q int, set *[]int) {
	p1, p2 := find(p, set), find(q, set)
	if p1 == p2 {
		return
	}
	if (*set)[p1] <= (*set)[p2] {
		(*set)[p1] += (*set)[p2]
		(*set)[p2] = p1
	} else {
		(*set)[p2] += (*set)[p1]
		(*set)[p1] = p2
	}
}

func countPairs(n int, edges [][]int) int64 {
	ds := make([]int, n)
	for i := range ds {
		ds[i] = -1
	}
	for i := range edges {
		union(edges[i][0], edges[i][1], &ds)
	}

	a, b := int64(0), int64(0)
	for i := range ds {
		if ds[i] < 0 {
			a += int64(ds[i])
			b += int64(ds[i]) * int64(ds[i])
		}
	}
	return (a*a - b) / 2
}
