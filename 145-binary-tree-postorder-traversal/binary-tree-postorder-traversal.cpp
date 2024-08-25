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
    vector<int> postorderTraversal(TreeNode* root) {
        // 25.08.24 POTD
        vector<int> ans;
        pot(root,ans);

        return ans;
    }

    void pot(TreeNode* nd, vector<int>& ans){
        if(!nd) return;

        pot(nd->left, ans);
        pot(nd->right, ans);

        ans.push_back(nd->val);
    }
};