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
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    int ret = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      ret += size;
      for (; size > 0; size--) {
        if (q.front()->left)
          q.push(q.front()->left);
        if (q.front()->right)
          q.push(q.front()->right);
        q.pop();
      }
    }
    return ret;
  }
};
