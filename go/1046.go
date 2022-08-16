package main

import (
	"container/heap"
)

type Heap []int

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
	return (*h)[i] > (*h)[j] // to make a max heap
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

func lastStoneWeight(stones []int) int {
	h := &Heap{}
	heap.Init(h)
	for _, v := range stones {
		heap.Push(h, v)
	}
	for h.Len() > 1 {
		x := heap.Pop(h).(int)
		y := heap.Pop(h).(int)
		heap.Push(h, x-y)
	}
	return heap.Pop(h).(int)
}
