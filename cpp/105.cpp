#include <iostream>
#include <map>
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
  TreeNode *construct(vector<int> &p, map<int, int> &indexOf, int root, int l,
                      int r) {
    if (l > r)
      return nullptr;

    int pivot = indexOf[p[root]];
    TreeNode *cur = new TreeNode(p[root]);

    cur->left = construct(p, indexOf, root + 1, l, pivot - 1);
    cur->right = construct(p, indexOf, root + pivot - l + 1, pivot + 1, r);
    return cur;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    map<int, int> indexOf;
    for (int i = 0; i < inorder.size(); i++)
      indexOf[inorder[i]] = i;
    return construct(preorder, indexOf, 0, 0, preorder.size() - 1);
  }
};
