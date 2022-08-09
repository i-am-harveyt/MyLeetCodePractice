#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
      if (p->val > q->val) {
          TreeNode *tmp = q;
          q = p;
          p = tmp;
      }
      int pv = p->val, qv = q->val;
      TreeNode *ret = root;
      while (true) {
          if (ret->val < pv)
              ret = ret->right;
          else if (ret->val > qv)
              ret = ret->left;
          else break;
      }
      return ret;
  }
};
