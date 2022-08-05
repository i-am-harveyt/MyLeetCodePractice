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
  TreeNode *helper(vector<int> &p, unordered_map<int, int> &m, int &root, int l,
                   int r) {
    if (r < l)
      return nullptr;

    int pivot = m[p[root]];

    TreeNode *cur = new TreeNode(p[root--]);
    cur->right = helper(p, m, root, pivot + 1, r);
    cur->left = helper(p, m, root, l, pivot - 1);

    return cur;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
      m[inorder[i]] = i;
    int lastIndex = postorder.size() - 1;
    return helper(postorder, m, lastIndex, 0, postorder.size() - 1);
  }
};
