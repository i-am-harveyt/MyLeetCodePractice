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

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ret{};
    if (root == nullptr)
      return ret;

    deque<TreeNode *> dq;

    dq.push_back(root);
    bool l2r = true;
    int layer = 0, count = 0;
    TreeNode *cur;
    while (!dq.empty()) {
      ret.push_back(vector<int>{});

      count = dq.size();
      while (count > 0) {
        // get currrent
        if (layer % 2 == 0) {
          cur = dq.front();
          dq.pop_front();
        } else {
          cur = dq.back();
          dq.pop_back();
        }

        ret[layer].push_back(cur->val);

        // push to deque
        if (layer % 2 == 0) {
          if (cur->left != nullptr) {
            dq.push_back(cur->left);
          }
          if (cur->right != nullptr) {
            dq.push_back(cur->right);
          }

        } else {
          if (cur->right != nullptr) {
            dq.push_front(cur->right);
          }
          if (cur->left != nullptr) {
            dq.push_front(cur->left);
          }
        }
        count--;
      }

      layer++;
    }

    return ret;
  }
};
