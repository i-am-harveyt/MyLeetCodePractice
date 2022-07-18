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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        
        TreeNode *cur = root;
        vector<TreeNode *>st;
        
        while (!st.empty() || cur != nullptr) {
            while (cur != nullptr) {
                ret.push_back(cur->val);
                st.push_back(cur);
                cur = cur->left;
            }
            
            cur = st.back();
            st.pop_back();
            
            cur = cur->right;
        }
        
        return ret;
    }
};
