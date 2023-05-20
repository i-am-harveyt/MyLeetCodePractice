package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNodes(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	ms := make([]*ListNode, 0)
	cur := head
	for cur != nil {
		for len(ms) > 0 && cur.Val > ms[len(ms)-1].Val {
			ms = ms[:len(ms)-1]
		}
		ms = append(ms, cur)
		cur = cur.Next
	}
	for i := 0; i < len(ms)-1; i++ {
		ms[i].Next = ms[i+1]
	}
	ms[len(ms)-1].Next = nil
	return ms[0]
}
