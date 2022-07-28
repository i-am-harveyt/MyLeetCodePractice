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

#include <iostream>
#include <vector>
using namespace std;

class SolutionDFS {
public:
  void dfs(TreeNode *cur, int layer, vector<vector<int>> &ret) {
    if (cur == nullptr)
      return;
    if (ret.size() < layer + 1)
      ret.push_back(vector<int>{});

    ret[layer].push_back(cur->val);

    dfs(cur->left, layer + 1, ret);
    dfs(cur->right, layer + 1, ret);
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ret{};

    dfs(root, 0, ret);

    return ret;
  }
};

class SolutionBFS {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ret{};

    if (root == nullptr)
      return ret;

    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));

    TreeNode *node;
    int layer;
    while (!q.empty()) {
      pair<TreeNode *, int> cur = q.front();
      node = cur.first;
      layer = cur.second;
      q.pop();
      if (ret.size() < layer + 1)
        ret.push_back(vector<int>{});

      ret[layer].push_back(node->val);
      if (node->left != nullptr)
        q.push(make_pair(node->left, layer + 1));
      if (node->right != nullptr)
        q.push(make_pair(node->right, layer + 1));
    }

    return ret;
  }
};
