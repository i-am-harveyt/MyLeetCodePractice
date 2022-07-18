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
  TreeNode *first, *second, *prev;
  void inOrder(TreeNode *current) {
    if (current == nullptr)
      return;

    inOrder(current->left);

    if (!first && current->val < prev->val)
      first = prev;
    if (first && current->val < prev->val)
      second = current;
    prev = current;

    inOrder(current->right);
  }

  void recoverTree(TreeNode *root) {
    prev = new TreeNode(INT_MIN);
    inOrder(root);
    swap(first->val, second->val);
  }
};
