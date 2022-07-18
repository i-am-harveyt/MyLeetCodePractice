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
  bool dfs(TreeNode *root, int cur, int targetSum) {
    if (!root)
      return false;
    else if (root->left == root->right && cur + root->val == targetSum) {
      return true;
      return false;
    }
    return dfs(root->left, cur + root->val, targetSum) ||
           dfs(root->right, cur + root->val, targetSum);
  }

  bool hasPathSum(TreeNode *root, int targetSum) {
    // do
    return dfs(root, 0, targetSum);
  }
};
