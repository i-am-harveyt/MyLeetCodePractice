#include <iostream>
#include <unordered_set>

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
  bool dfs(TreeNode *t, int k, unordered_set<int> &s) {
    if (!t)
      return false;
    if (s.find(t->val) != s.end()) // if there is a num + t->val == k
      return true;
    s.insert(k - t->val); // update
    return dfs(t->left, k, s) || dfs(t->right, k, s);
  }
  bool findTarget(TreeNode *root, int k) {
    unordered_set<int> remain;
    return dfs(root, k, remain);
  }
};
