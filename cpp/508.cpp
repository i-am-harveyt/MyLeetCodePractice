#include <algorithm>
#include <iostream>
#include <unordered_map>
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
  int helper(TreeNode *t, unordered_map<int, int> &m) {
    if (!t)
      return 0;
    int l = helper(t->left, m), r = helper(t->right, m);
    int sum = t->val + l + r;
    m[sum]++;
    return sum;
  }
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> freq;
    helper(root, freq);
    int maxFreq = 0;
    vector<int> ret;
    for (auto &t : freq) {
      if (t.second == maxFreq) {
        ret.push_back(t.first);
      } else if (t.second > maxFreq) {
        ret.clear();
        maxFreq = t.second;
        ret.push_back(t.first);
      }
    }
    return ret;
  }
};
