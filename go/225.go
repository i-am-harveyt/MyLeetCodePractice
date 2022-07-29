package main

type MyStack struct {
	q   []int
	top int
}

func Constructor() MyStack {
	st := MyStack{}
	st.q = make([]int, 0)
	st.top = 0
	return st
}

func (this *MyStack) Push(x int) {
	if this.top == 0 {
		this.top = x
	} else {
		this.q = append(this.q, this.top)
		this.top = x
	}
}

func (this *MyStack) Pop() int {
	ret := this.Top()
	this.top = 0

	if len(this.q) > 0 {
		for i := 1; i < len(this.q); i++ {
			this.q = append(this.q, this.q[0])
			this.q = this.q[1:]
		}
		this.top = this.q[0]
		this.q = this.q[1:]
	}

	return ret
}

func (this *MyStack) Top() int {
	return this.top
}

func (this *MyStack) Empty() bool {
	if len(this.q) == 0 && this.top == 0 {
		return true
	}
	return false
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
