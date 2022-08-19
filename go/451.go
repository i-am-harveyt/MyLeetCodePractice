package main

import (
	"container/heap"
	"strings"
)

type Heap []Pair

// Len implements heap.Interface
func (h *Heap) Len() int {
	return len(*h)
}

// Less implements heap.Interface
func (h *Heap) Less(i int, j int) bool {
	return (*h)[i].Freq > (*h)[j].Freq
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
  *h = append(*h, x.(Pair))
}

type Pair struct {
	Freq int
	Char byte
}

func frequencySort(s string) string {
  var freq map[byte]int = make(map[byte]int)
  for i := range s {
    freq[s[i]]++
  }
	var h *Heap = &Heap{}
	heap.Init(h)
	for k, v := range freq {
	  heap.Push(h, Pair{Freq: v, Char: k})
	}
	var ret strings.Builder
	for h.Len() > 0 {
	  var top Pair = heap.Pop(h).(Pair)
	  for i := 0 ; i < top.Freq ; i++ {
	    ret.WriteByte(top.Char)
	  }
	}
	return ret.String()
}
