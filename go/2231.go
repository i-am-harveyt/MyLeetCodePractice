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

func largestInteger(num int) int {
  // init min heap for odd and even nums
	var ho, he *Heap = &Heap{}, &Heap{}
	heap.Init(ho)
	heap.Init(he)

	// scan all number and categorize them
	var tmp, cur int = num, 0
	for tmp > 0 {
	  cur = tmp % 10
	  if cur % 2 == 1 {
	    heap.Push(ho, cur)
	  } else {
	    heap.Push(he, cur)
	  }
	  tmp /= 10
	}

	// put them into ret
	var ret, w = 0, 1
	for true {
	  cur = num % 10
	  if cur % 2 == 1 {
	    ret += heap.Pop(ho).(int) * w
	  } else {
	    ret += heap.Pop(he).(int) * w
	  }
	  num /= 10
	  if num > 0 {
	    w *= 10
	  } else {
	    break
	  }
	}
	return ret
}
