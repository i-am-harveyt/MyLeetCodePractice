package main

import "container/heap"

type Heap []int

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
	return (*h)[i] > (*h)[j] // make a max heap
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

func fillCups(amount []int) int {
	var h *Heap = &Heap{}
	heap.Init(h)

	// scan numbers
	for i := 0; i < len(amount); i++ {
		if amount[i] > 0 {
			heap.Push(h, amount[i])
		}
	}

	// calculate
	var ret int = 0
	for h.Len() > 0 {
		var x int = heap.Pop(h).(int)
		// if x is only remain
		if h.Len() == 0 {
			ret += x
			return ret
		}
		// else, consider y and update x&y
		x--
		var y int = heap.Pop(h).(int)
		y--
		if y != 0 {
			heap.Push(h, y)
		}
		if x != 0 {
			heap.Push(h, x)
		}
		ret++
	}
	return ret
}
