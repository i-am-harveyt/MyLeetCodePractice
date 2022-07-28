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
    // helper function
    void post(TreeNode *cur, vector<int>& ret) {
        if (cur == nullptr)
            return;
        post(cur->left, ret);
        post(cur->right, ret);
        ret.push_back(cur->val); 
    }
    
    // Recursive method
    vector<int> postorderTraversalR(TreeNode* root) {
        vector<int> ret;
        post(root, ret);
        return ret;
    }

    // Iterative method
    vector<int> postorderTraversalI(TreeNode* root) {
        vector<int> ret;
        TreeNode *cur = root;
        vector<TreeNode *>st;

        while (!st.empty() || cur != nullptr) {
            while (cur != nullptr) {
                st.push_back(cur);
                st.push_back(cur);
                cur = cur->left;
            }

            cur = st.back();
            st.pop_back();

            if (st.size() > 0 && st.back() == cur)
                cur = cur->right;
            else {
                ret.push_back(cur->val);
                cur = nullptr;
            }
        }

        return ret;
    }
};
