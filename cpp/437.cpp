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
    // check TreeNode t is valid or not
  int check(TreeNode *t, long target) {
    if (!t) // t is nullptr
      return 0;
    target -= t->val;
    if (!target) // target == 0
        return 1 + check(t->left, target) + check(t->right, target);
    return check(t->left, target) + check(t->right, target);
  }
  int pathSum(TreeNode *root, int targetSum) {
    int ret = 0;
    vector<TreeNode *> st;
    TreeNode *cur = root;
    // iteratively dfs, using one stack
    while (!st.empty() || cur != nullptr) {
      while (cur != nullptr) {
        st.push_back(cur);
        cur = cur->left;
      }
      cur = st.back();
      ret += check(cur, long(targetSum));
      st.pop_back();

      cur = cur->right;
    }
    return ret;
  }
};
