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
  void helper(TreeNode *t, int depth, vector<double> &ret, vector<int> &cnt) {
    if (!t)
      return;
    if (depth > ret.size()) {
      ret.push_back(0);
      cnt.push_back(0);
    }
    ret[depth-1] = (ret[depth-1] * cnt[depth-1] + t->val) / (++cnt[depth]);
    depth++;
    helper(t->left, depth, ret, cnt);
    helper(t->right, depth, ret, cnt);
  }
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ret;
    vector<int> count;
    helper(root, 1, ret, count);
    return ret;
  }
};
