#include <iostream>
#include <queue>

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
  int deepestLeavesSum(TreeNode *root) {
    // use BFS method, with a queue to run through,
    // if the node has child, push child into queue, if not, add to sum
    int ret = 0, deepest = 0, curDepth;
    queue<pair<TreeNode *, int>> q;
    queue<pair<TreeNode *, int>> out;
    TreeNode *cur;
    q.push(pair<TreeNode *, int>(root, 0));

    while (!q.empty()) {
      cur = q.front().first;
      curDepth = q.front().second;

      if (cur->left)
        q.push(pair<TreeNode *, int>(cur->left, q.front().second + 1));
      if (cur->right)
        q.push(pair<TreeNode *, int>(cur->right, q.front().second + 1));

      if (!cur->left && !cur->right) {
        if (curDepth > deepest) {
          deepest = curDepth;
          ret = cur->val;
        } else if (curDepth == deepest) {
          ret += cur->val;
        }
      }

      q.pop();
    }

    return ret;
  }
};
