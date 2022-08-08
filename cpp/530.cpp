#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

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
  int ret = INT_MAX;
  TreeNode *prev;
  void inorder(TreeNode *cur) {
    if (cur == nullptr)
      return;
    inorder(cur->left);
    if (prev != nullptr)
      ret = min(ret, abs(cur->val - prev->val));
    prev = cur;
    inorder(cur->right);
  }
  int getMinimumDifference(TreeNode *root) {
    prev = nullptr;
    inorder(root);
    return ret;
  }
};
