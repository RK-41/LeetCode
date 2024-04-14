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
        // 14.04.24 POTD
        int ans=0;
        dfs(root, ans, 0);

        return ans;
    }

    void dfs(TreeNode* r, int &ans, int nd){
        if(!r)
            return;

        dfs(r->left, ans, -1);
        dfs(r->right, ans, 1);

        if(!r->left && !r->right && nd==-1)
            ans += r->val;
    }
};