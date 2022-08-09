#include <algorithm>
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ret;
    if (!root)
      return ret;
    vector<TreeNode *> q;
    q.push_back(root);
    int l = 0;
    while (!q.empty()) {
      int size = q.size();
      ret.push_back(vector<int>());
      for (int i = 0; i < size; i++) {
        ret[l].push_back(q[0]->val);
        if (q[0]->left)
          q.push_back(q[0]->left);
        if (q[0]->right)
          q.push_back(q[0]->right);
        q.erase(q.begin());
      }
      l++;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

class SolutionDFS {
public:
  vector<vector<int>> ret;
  void helper(TreeNode *t, int layer) {
    if (!t)
      return;
    if (ret.size() == layer) {
      ret.push_back(vector<int>());
    }
    ret[layer].push_back(t->val);
    helper(t->left, layer + 1);
    helper(t->right, layer + 1);
  }
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    helper(root, 0);
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
