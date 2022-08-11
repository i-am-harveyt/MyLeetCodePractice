#include <iostream>
#include <string>

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
  void helper(TreeNode *t, string &s) {
    if (!t)
      return;
    s += to_string(t->val);
    if (t->left || t->right) {
      s += "(";
      helper(t->left, s);
      s += ")";
      if (t->right) {
        s += "(";
        helper(t->right, s);
        s += ")";
      }
    }
  }
  string tree2str(TreeNode *root) {
    string ret = "";
    helper(root, ret);
    return ret;
  }
};
