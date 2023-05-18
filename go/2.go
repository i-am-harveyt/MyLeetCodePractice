package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	ret := &ListNode{Val: 0, Next: nil}
	cur := ret
	carry := false
	for l1 != nil || l2 != nil || carry {
		if l1 != nil {
			cur.Val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			cur.Val += l2.Val
			l2 = l2.Next
		}
		if carry {
			cur.Val += 1
			carry = false
		}
		if cur.Val >= 10 {
			carry = true
			cur.Val -= 10
		}
		if l1 != nil || l2 != nil || carry {
			cur.Next = new(ListNode)
		}
		cur = cur.Next
	}

	return ret
}
