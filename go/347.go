package main

import "container/heap"

type Heap [][]int

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
	return (*h)[i][0] < (*h)[j][0]
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
  *h = append(*h, x.([]int))
}

func topKFrequent(nums []int, k int) []int {
	var h *Heap = &Heap{}
	heap.Init(h)
	var m map[int]int = make(map[int]int)
	// get count of num
	for _,v := range nums {
	  m[v]++
	}
	// import into heap, and controll size
	for i, v := range m {
	  heap.Push(h, []int{v, i})
	  if h.Len() > k {
	    heap.Pop(h)
	  }
	}
	var ret []int = make([]int, 0)
	for h.Len() > 0 {
	  ret = append(ret, heap.Pop(h).([]int)[1])
	}
	return ret
}
