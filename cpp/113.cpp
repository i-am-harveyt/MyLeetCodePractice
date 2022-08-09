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
  void helper(TreeNode *t, int curSum, vector<int> &v) {
    if (!t) // if current node is null
      return;
    int sum = curSum + t->val;
    v.push_back(t->val);
    if (sum == target && !t->left && !t->right) { // sum matched, and t is leaf
      ret.push_back(vector<int>());
      ret.back().assign(v.begin(), v.end());
      v.pop_back();
      return;
    }
    // recursivly check
    helper(t->left, sum, v);
    helper(t->right, sum, v);

    // remove current value to back-tracking
    v.pop_back();
  }
  vector<vector<int>> ret;
  int target;
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    target = targetSum;
    vector<int> vec = vector<int>();
    helper(root, 0, vec);
    return ret;
  }
};
