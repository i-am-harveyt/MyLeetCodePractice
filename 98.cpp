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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode *> st;
        vector<int> order;
        TreeNode *cur = root;
        
        while (!st.empty() || cur != nullptr) {
            while (cur != nullptr) {
                st.push_back(cur);
                cur = cur->left;
            } 
            
            cur = st.back();
            order.push_back(cur->val);
            st.pop_back();
            
            cur = cur->right;
        }
        
        for (int i = 1 ; i < order.size() ; i++)
            if (order[i] <= order[i-1])
                return false;
        
        return true;
    }
};
