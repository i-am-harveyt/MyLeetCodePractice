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
  int findBottomLeftValue(TreeNode *root) {
      queue<TreeNode *> q;
      q.push(root);
      int ret, size;

      // BFS method
      while (!q.empty()) {
          size = q.size();
          // get the leftist of this layer
          ret = q.front()->val;
          while (size) { // I found this may use for loop when I writing Go, haha
              if (q.front()->left)
                  q.push(q.front()->left);
              if (q.front()->right)
                  q.push(q.front()->right);
              q.pop();
              size--;
          }
      }

      return ret;
  }
};
