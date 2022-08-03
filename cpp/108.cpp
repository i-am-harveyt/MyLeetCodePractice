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
  TreeNode *insert(vector<int> &arr, int l, int r) {
    if (l > r)
      return nullptr;
    int mid = l + (r - l) / 2;
    TreeNode *cur = new TreeNode(arr[mid]);
    cur->left = insert(arr, l, mid - 1);
    cur->right = insert(arr, mid + 1, r);
    return cur;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return insert(nums, 0, nums.size() - 1);
  }
};
