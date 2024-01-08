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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // 08.01.24 POTD
        int ans=0;
        dfs(root, low, high, ans);

        return ans;
    }

    void dfs(TreeNode* root, int& l, int& h, int& ans){
        if(!root)
            return;

        dfs(root->left, l, h, ans);
        
        if(root->val >= l && root->val <=h)
            ans += root->val;

        dfs(root->right, l, h, ans);
    }
};