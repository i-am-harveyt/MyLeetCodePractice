#include <algorithm>
#include <climits>
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
  int path(TreeNode *cur) {
    if (cur == nullptr)
      return 0;
    int left = path(cur->left);
    int right = path(cur->right);
    if (ret < left + right)
      ret = left + right;
    return max(left, right) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root) {
    ret = INT_MIN;
    path(root);
    return ret;
  }
};
