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
  TreeNode *right(TreeNode *t, int v, int d) { // right subtree
    if (d == 1) {                              // target depth
      TreeNode *l = new TreeNode(v, nullptr, t);
      return l;
    }
    if (!t) // leaf but not reach target depth
      return nullptr;
    d--;                              // update depth
    t->left = left(t->left, v, d);    // recursive
    t->right = right(t->right, v, d); // recursive
    return t;
  }
  TreeNode *left(TreeNode *t, int v, int d) {
    if (d == 1) {
      TreeNode *r = new TreeNode(v, t, nullptr);
      return r;
    }
    if (!t)
      return nullptr;
    d--;
    t->left = left(t->left, v, d);
    t->right = right(t->right, v, d);
    return t;
  }
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    return left(root, val, depth); // treat root as left subtree case
  }
};
