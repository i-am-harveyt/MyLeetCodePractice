#include <iostream>
#include <stack>
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
  vector<int> inorderTraversal(TreeNode *root) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> out;
    if (root == nullptr)
      return out;
    stack<TreeNode *> s;
    TreeNode *current = root;

    while (!s.empty() || current != nullptr) {

      while (current != nullptr) {
        s.push(current);
        current = current->left;
      }

      current = s.top();
      out.push_back(current->val);
      s.pop();

      cout << current->val << endl;

      current = current->right;
    }

    return out;
  }
};
