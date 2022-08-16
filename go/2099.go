package main

import (
	"container/heap"
	"sort"
)

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

func maxSubsequence(nums []int, k int) []int {
	var h *Heap = &Heap{}
	heap.Init(h)
	var ret []int = make([]int, 0)
	for i, v := range nums {
		heap.Push(h, []int{v, i})
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	var tmp [][]int = make([][]int, 0)
	for h.Len() > 0 {
		tmp = append(tmp, heap.Pop(h).([]int))
	}
	sort.Slice(tmp, func(i, j int) bool {
		return tmp[i][1] < tmp[j][1]
	})
	for i := 0 ; i < len(tmp) ; i++ {
		ret = append(ret, tmp[i][0])
	}
	return ret
}
