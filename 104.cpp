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
  int dfs(TreeNode *n, int d) {
    if (n == nullptr)
      return d;
    return max(dfs(n->left, d + 1), dfs(n->right, d + 1));
  }

  int maxDepth(TreeNode *root) { return dfs(root, 0); }
};
