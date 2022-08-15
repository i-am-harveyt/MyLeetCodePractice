package main

import (
	"container/heap"
)

type Heap []int

// Len implements heap.Interface
func (h Heap) Len() int {
	return len(h)
}

// Less implements heap.Interface
func (h Heap) Less(i int, j int) bool {
	return h[i] < h[j]
}

// Swap implements heap.Interface
func (h Heap) Swap(i int, j int) {
	h[i], h[j] = h[j], h[i]
}

// Pop implements heap.Interface
func (h *Heap) Pop() interface{} {
	ret := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return ret
}

// Push implements heap.Interface
func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *Heap) Peek() interface{} {
	return (*h)[0]
}

type KthLargest struct {
	heap *Heap
	size int
}

func Constructor(k int, nums []int) KthLargest {
	h := &Heap{}
	heap.Init(h)
	for _, v := range nums {
		heap.Push(h, v)
	}
	for h.Len() > k {
		heap.Pop(h)
	}
	return KthLargest{
		heap: h,
		size: k,
	}
}

func (this *KthLargest) Add(val int) int {
	heap.Push(this.heap, val)
	if this.heap.Len() > this.size {
		heap.Pop(this.heap)
	}
	return this.heap.Peek().(int)
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
