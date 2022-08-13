#include <iostream>
#include <math.h>
#include <string>
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
  // get max height
  void traverse(TreeNode *t, int &h, int curh) {
    if (!t)
      return;
    if (curh > h)
      h = curh;
    traverse(t->left, h, curh + 1);
    traverse(t->right, h, curh + 1);
  }

  // build answer array, binary-search-like method
  void build(vector<vector<string>> &ret, TreeNode *t, int depth, int l,
             int r) {
    if (!t || l > r)
      return;
    int mid = l + (r - l) / 2;
    ret[depth][mid] = to_string(t->val);
    build(ret, t->left, depth + 1, l, mid - 1);
    build(ret, t->right, depth + 1, mid + 1, r);
  }
  vector<vector<string>> printTree(TreeNode *root) {
    vector<vector<string>> ret;
    int h = 0;
    traverse(root, h, 0); // get height
    for (int i = 0; i <= h; i++) // build answer array
      ret.push_back(vector<string>(int(pow(2, h + 1)) - 1, ""));
    build(ret, root, 0, 0, ret[0].size() - 1);
    return ret;
  }
};
