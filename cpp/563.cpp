#include <cstdlib>
#include <iostream>

using namespace std;

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
  int ret;
  int helper(TreeNode *cur) {
    if (!cur)
      return 0;
    int ls = helper(cur->left), rs = helper(cur->right);
    ret += abs(ls - rs);
    return cur->val + ls + rs;
  }
  int findTilt(TreeNode *root) {
    ret = 0;
    helper(root);
    return ret;
  }
};
