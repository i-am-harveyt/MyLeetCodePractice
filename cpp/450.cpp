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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return nullptr;
    // searching
    if (key < root->val)
      root->left = deleteNode(root->left, key);
    else if (key > root->val)
      root->right = deleteNode(root->right, key);
    else { // if root is target
      if (!root->left && !root->right) { // root is leaf
        return nullptr;
      } else if (!root->left || !root->right) { // root has one child
        TreeNode *ret = !root->left ? root->right : root->left;
        return ret;
      }
      // if have two child, replace root->val by the largest num in
      // left subtree, and delete it
      TreeNode *n = root->left;
      while (n->right)
        n = n->right;
      root->val = n->val;
      root->left = deleteNode(root->left, n->val);
    }
    return root;
  }
};
