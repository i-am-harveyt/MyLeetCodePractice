package main

import (
	"container/heap"
	"fmt"
	"math"
)

type Heap [][]int // structure: [[sum, idx1, idx2]]

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

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {

	var h *Heap = &Heap{}
	var seen map[[2]int]int = make(map[[2]int]int, 0)
	heap.Init(h)

	var l1, l2 = len(nums1), len(nums2)
	var lmt int = int(math.Min(float64(k), float64(l1*l2)))
	heap.Push(h, []int{nums1[0] + nums2[0], 0, 0})
	seen[[2]int{0, 0}] = 1
	var ret [][]int = make([][]int, 0)
	for ; lmt > 0; lmt-- {
		top := heap.Pop(h).([]int)
		i, j := top[1], top[2]
		ret = append(ret, []int{nums1[i], nums2[j]})
		if i+1 < l1 && seen[[2]int{i + 1, j}] == 0 {
			heap.Push(h, []int{nums1[i+1] + nums2[j], i + 1, j})
			seen[[2]int{i + 1, j}]++
		}
		if j+1 < l2 && seen[[2]int{i, j + 1}] == 0 {
			heap.Push(h, []int{nums1[i] + nums2[j+1], i, j + 1})
			seen[[2]int{i, j + 1}]++
		}
	}
	return ret
}

func main() {
	fmt.Print(kSmallestPairs([]int{1, 7, 11}, []int{2, 4, 6}, 3))
}
