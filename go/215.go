package main

import "container/heap"

type Heap []int

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
	return (*h)[i] > (*h)[j]
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

func findKthLargest(nums []int, k int) int {
	var h *Heap = &Heap{}
	heap.Init(h)
	for _, v := range nums {
	  heap.Push(h, v)
	}
	for ; k > 1; k-- { // pop 1st to k-1th largest
		heap.Pop(h)
	}
	return heap.Pop(h).(int)
}
