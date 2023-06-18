from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return

        prev, cur = head, head.next
        while cur:
            if cur.val == prev.val:
                cur = cur.next
                del prev.next
                prev.next = cur
            else:
                prev, cur = cur, cur.next

        return head
