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
  bool b = true;
  int dfs(TreeNode *n, int h) {
    if (n == nullptr)
      return h;
    int left = dfs(n->left, h + 1), right = dfs(n->right, h + 1);
    if (abs(left - right) > 1)
      b = false;
    return max(left, right);
  }
  bool isBalanced(TreeNode *root) {
    dfs(root, 0);
    return b;
  }
};
