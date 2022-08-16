package main

import "container/heap"

type Heap []int

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
	return (*h)[i] < (*h)[j]
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

func (h *Heap) Top() int {
	return (*h)[0]
}

func minimumOperations(nums []int) int {
	var h *Heap = &Heap{}
	heap.Init(h)
	for _, v := range nums {
		if v != 0 {
			heap.Push(h, v)
		}
	}
	var ret int = 0
	for h.Len() > 0 {
		var x = heap.Pop(h)
		for h.Len() > 0 && h.Top() == x { // push until top != x
			heap.Pop(h)
		}
		ret++
	}
	return ret
}
