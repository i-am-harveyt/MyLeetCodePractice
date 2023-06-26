from typing import Optional
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root: Optional[TreeNode], lb: int, rb: int):
        if root is None:
            return True
        elif root.left and root.val <= root.left.val:
            return False
        elif root.right and root.val >= root.right.val:
            return False
        elif root.val <= lb or root.val >= rb:
            return False
        return self.helper(root.left, lb, root.val) and \
            self.helper(root.right, root.val, rb)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root, -2**31-1, 2**31)
