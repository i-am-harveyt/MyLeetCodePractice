#include <iostream>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool contains1(TreeNode *cur) {
        if (!cur)
            return false;
        bool left = contains1(cur->left);
        bool right = contains1(cur->right);
        if (!left) {
            delete cur->left;
            cur->left = nullptr;
        }
        if (!right) {
            delete cur->right;
            cur->right = nullptr;
        }
        return left || right || cur->val;
    }
    TreeNode* pruneTree(TreeNode *root) {
        bool forRoot = contains1(root);
        if (!forRoot)
            return nullptr;
        return root;
    }
};
