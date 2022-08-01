package main

type RecentCounter struct {
	q []int
}

func Constructor() RecentCounter {
	return RecentCounter{make([]int, 0)}
}

func (this *RecentCounter) Ping(t int) int {
	var span int = 3000
	var bound int = t - span

	this.q = append(this.q, t)
	for this.q[0] < bound {
		this.q = this.q[1:]
	}

	return len(this.q)
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
