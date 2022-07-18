/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *cur, *left, *right;
        int ret = 0;
        while (!q.empty()) {
            cur = q.front();
            left = cur->left, right = cur->right;
            q.pop();
            if (left != nullptr) {
                if (left->left == left->right) // is a leaf
                    ret += left->val;
                else
                    q.push(left);
            }
            if (right != nullptr) 
                q.push(right);
            
        }
        
        return ret;
    }
};
