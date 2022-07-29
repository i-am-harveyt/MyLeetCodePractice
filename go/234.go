package main

// Definition for singly-linked list.
// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

func isPalindrome(head *ListNode) bool {
	var size int = 0
	var cur *ListNode = head
	for cur != nil {
		size++
		cur = cur.Next
	}

	var mid int = 0
	if size == 1 {
		return true
	} else if size%2 == 0 {
		mid = size / 2
	} else {
		mid = size/2 + 1
	}

	cur = head
	var st []int = make([]int, 0)
	for i := 1; i <= mid; i++ {
		st = append(st, cur.Val)
		cur = cur.Next
	}
	if size%2 == 1 {
		st = st[:len(st)-1]
	}
	for cur != nil {
		if cur.Val != st[len(st)-1] {
			return false
		}
		st = st[:len(st)-1]
		cur = cur.Next
	}

	return true
}
