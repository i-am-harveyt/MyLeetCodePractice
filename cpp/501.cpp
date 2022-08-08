#include <climits>
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
  vector<int> ret;
  int maxFreq = 0, curFreq = 0, preVal = INT_MIN;
  void helper(TreeNode *cur) {
    if (cur == nullptr)
      return;
    helper(cur->left);

    if (cur->val == preVal)
      curFreq++;
    else {
      preVal = cur->val;
      curFreq = 1;
    }

    if (curFreq > maxFreq) {
      ret.clear();
      ret.push_back(cur->val);
      maxFreq = curFreq;
    } else if (curFreq == maxFreq) {
      ret.push_back(cur->val);
    }

    helper(cur->right);
  }

  vector<int> findMode(TreeNode *root) {
    helper(root);
    return ret;
  }
};
