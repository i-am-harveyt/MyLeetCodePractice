#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *find(TreeNode *r, TreeNode *p, TreeNode *q) {
    if (!r || r == p || r == q)
      return r;
    TreeNode *left = find(r->left, p, q), *right = find(r->right, p, q);
    if (left && right)
      return r;
    else if (left)
      return left;
    else if (right)
      return right;
    return nullptr;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return find(root, p, q);
  }
};
