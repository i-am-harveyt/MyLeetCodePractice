#include <iostream>
#include <string>
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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ret;                  // return vector
    vector<TreeNode *> stn;              // stack for nodes
    vector<string> stp;                  // stack for paths
    stn.push_back(root);                 // init
    stp.push_back(to_string(root->val)); // init
    TreeNode *cur;
    string path;
    while (!stn.empty()) {
      cur = stn.back(); // get current node
      stn.pop_back();
      path = stp.back(); // get current path
      stp.pop_back();
      if (cur->left == nullptr && cur->right == nullptr) { // leaf
        ret.push_back(path);
      }
      if (cur->left != nullptr) { // there is left child
        stn.push_back(cur->left);
        stp.push_back(path + "->" + to_string(cur->left->val));
      }
      if (cur->right != nullptr) { // there is right child
        stn.push_back(cur->right);
        stp.push_back(path + "->" + to_string(cur->right->val));
      }
    }
    return ret;
  }
};
