#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  void helper(TreeNode* cur, int curSum, int &total) {
    curSum = 10*curSum + cur->val;
    if (cur->left)
      helper(cur->left, curSum, total);
    if (cur->right)
      helper(cur->right, curSum, total);
    if (!cur->left && !cur->right)
      total += curSum;
  }
  int sumNumbers(TreeNode *root) {
    int ret = 0;
    helper(root, 0, ret);
    return ret;
  }
};
