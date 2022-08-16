package main

import "container/heap"

type Heap []int

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
	return (*h)[i] >= (*h)[j]
}

// Swap implements heap.Interface
func (h *Heap) Swap(i int, j int) {
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
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

func maxProduct(nums []int) int {
	var h *Heap = &Heap{}
	heap.Init(h)
	for _, v := range nums {
		heap.Push(h, v)
	}

	// return (largest-1)*(2nd_largest-1)
	return (heap.Pop(h).(int) - 1) * (heap.Pop(h).(int) - 1)
}
