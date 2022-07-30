package main

import "math"

type MinStack struct {
	st  []int
	min int
}

func Constructor() MinStack {
	return MinStack{make([]int, 0), math.MaxInt32}
}

func (this *MinStack) Push(val int) {
	if val <= this.min {
		this.st = append(this.st, this.min)
		this.min = val
	}
	this.st = append(this.st, val)
}

func (this *MinStack) Pop() {
	if this.st[len(this.st)-1] == this.GetMin() {
		this.min = this.st[len(this.st)-2]
		this.st = this.st[:len(this.st)-2]
	} else {
		this.st = this.st[:len(this.st)-1]
	}
}

func (this *MinStack) Top() int {
	return this.st[len(this.st)-1]
}

func (this *MinStack) GetMin() int {
	return this.min
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
