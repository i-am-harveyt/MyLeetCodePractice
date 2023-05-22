package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	curA, curB, cnt := headA, headB, 0
	for cnt < 3 {
		if curA == nil {
			curA = headB
			cnt++
		}
		if curB == nil {
			curB = headA
			cnt++
		}
		if curA == curB {
			return curA
		}
		curA = curA.Next
		curB = curB.Next
	}
	return nil
}
