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
  bool identical(TreeNode *t, TreeNode *s) {
    if (!t && !s)
      return true;
    else if (!t || !s)
      return false;
    else if (t->val == s->val)
      return identical(t->left, s->left) && identical(t->right, s->right);
    return false;
  }
  bool helper(TreeNode *t, TreeNode *s) {
    if (!t && !s)
      return true;
    else if (!t || !s)
      return false;
    else if (t->val == s->val) {
      if (identical(t, s))
        return true;
    }
    return helper(t->left, s) || helper(t->right, s);
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    return helper(root, subRoot);
  }
};
