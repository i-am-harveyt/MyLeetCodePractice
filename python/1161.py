from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        ret, lv = 0, 1
        max = -1 << 31
        queue = [root]

        while len(queue):
            size = len(queue)
            sum = 0
            for _ in range(size):
                head = queue[0]
                sum += head.val
                if head.left:
                    queue.append(head.left)
                if head.right:
                    queue.append(head.right)
                queue = queue[1:]
            if sum > max:
                ret = lv
                max = sum
            lv += 1

        return ret
