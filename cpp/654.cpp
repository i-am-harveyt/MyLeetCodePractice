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
  TreeNode *build(vector<int> &nums, int l, int r) {
    if (l > r)
      return nullptr;
    // find max element
    int m = l;
    for (int i = l + 1; i <= r; i++)
      if (nums[i] > nums[m])
        m = i;
    // build
    TreeNode *ret = new TreeNode(nums[m]);
    ret->left = build(nums, l, m - 1);
    ret->right = build(nums, m + 1, r);
    return ret;
  }
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return build(nums, 0, nums.size() - 1);
  }
};
