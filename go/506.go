package main

import (
	"container/heap"
	"strconv"
)

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

func findRelativeRanks(score []int) []string {
	var h *Heap = &Heap{}
	heap.Init(h)
	for _, v := range score { // let heap to sort for us
		heap.Push(h, v)
	}
	var m map[int]string = make(map[int]string) // get a score->rank condition
	// special condition: 1st, 2nd, 3nd
	if len(score) >= 1 {
		m[heap.Pop(h).(int)] = "Gold Medal"
	}
	if len(score) >= 2 {
		m[heap.Pop(h).(int)] = "Silver Medal"
	}
	if len(score) >= 3 {
		m[heap.Pop(h).(int)] = "Bronze Medal"
	}
	// others
	for i := 4; i <= len(score); i++ {
		m[heap.Pop(h).(int)] = strconv.Itoa(i)
	}

	// export to output
	var ret []string = make([]string, 0)
	for i := 0; i < len(score); i++ {
		ret = append(ret, m[score[i]])
	}
	return ret
}
