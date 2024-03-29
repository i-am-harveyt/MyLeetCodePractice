#include <climits>
#include <cstddef>
#include <queue>

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
  int maxLevelSum(TreeNode *root) {
    size_t ret{0}, level{1};
    int max{INT_MIN};

    std::queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
      size_t size{q.size()};
      int sum{0};
      while (size) {
        TreeNode *cur{q.front()};
        q.pop();
        sum += cur->val;
        --size;
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
      if (sum > max)
        max = sum, ret = level;
      ++level;
    }

    return ret;
  }
};
