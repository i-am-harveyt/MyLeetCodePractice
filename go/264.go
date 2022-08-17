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

func nthUglyNumber(n int) int {
	var h *Heap = &Heap{}
	heap.Init(h)
	heap.Push(h, 1)
	var m map[int]uint8 = make(map[int]uint8)
	var cur int
	for n > 1 {
		cur = heap.Pop(h).(int)
		if m[cur*2] == 0 {
			heap.Push(h, cur*2)
			m[cur*2]++
		}
		if m[cur*3] == 0 {
			heap.Push(h, cur*3)
			m[cur*3]++
		}
		if m[cur*5] == 0 {
			heap.Push(h, cur*5)
			m[cur*5]++
		}
		n--
	}
	return int(heap.Pop(h).(int))
}
