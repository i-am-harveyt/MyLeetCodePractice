package main

type Heap struct {
	Size  int
	Queue []int
}

func Push(this *Heap, val int) {
	this.Queue = append(this.Queue, val)
	this.Size++
	for i := this.Size / 2; i >= 0; i-- {
		Heapify(this, i)
	}
}

func Pop(this *Heap) {
	this.Queue = this.Queue[1:]
	this.Size--
	for i := this.Size / 2; i >= 0; i-- {
		Heapify(this, i)
	}
}

func Top(this *Heap) int {
	return this.Queue[0]
}

func Swap(this *Heap, i, j int) {
	this.Queue[i], this.Queue[j] = this.Queue[j], this.Queue[i]
}

func Heapify(this *Heap, i int) {
	var j int = i*2 + 1
	for j < this.Size {
		if j+1 < this.Size && this.Queue[j+1] > this.Queue[j] {
			j++
		}
		if this.Queue[i] < this.Queue[j] {
			Swap(this, i, j)
			i = j
			j = 2*j + 1
		} else {
			break
		}
	}
}

type KthLargest struct {
	Q    Heap
	Size int
}

func Constructor(k int, nums []int) KthLargest {
	var ret KthLargest = KthLargest{Q: Heap{Queue: make([]int, 0), Size: 0}}
	ret.Size = k
	for _, v := range nums {
		Push(&(ret.Q), 0-v)
		if ret.Q.Size > ret.Size {
			Pop(&(ret.Q))
		}
	}
	return ret
}

func (this *KthLargest) Add(val int) int {
	Push(&(this.Q), 0-val)
	if this.Q.Size > this.Size {
		Pop(&(this.Q))
	}
	return 0 - Top(&(this.Q))
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
