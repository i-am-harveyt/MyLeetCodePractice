package main

import (
	"container/heap"
)

type Heap [][]int

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
  if (*h)[i][0] == (*h)[j][0] {
    return (*h)[i][1] < (*h)[j][1]
  }
  return (*h)[i][0] >= (*h)[j][0]
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

func kWeakestRows(mat [][]int, k int) []int {
	var ret []int = make([]int, 0)
	var h *Heap = &Heap{}
	heap.Init(h)
	for i := 0; i < len(mat); i++ {
		var count int = 0
		for j := 0; j < len(mat[i]); j++ {
			count += mat[i][j]
		}
		heap.Push(h, []int{count, i})
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	for h.Len() > 0 {
		ret = append(ret, heap.Pop(h).([]int)[1])
	}

	// reverse ret: weak -> strong
	for i, j := 0, len(ret)-1; i < j; i, j = i+1, j-1 {
		ret[i], ret[j] = ret[j], ret[i]
	}

	return ret
}
