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
    int sumNumbers(TreeNode* root) {
        // 15.04.24 POTD
        int ans=0;
        dfs(root, ans);
        
        return ans;
    }

    void dfs(TreeNode* r, int &ans, int p=0){
        if(!r)  return;

        int num = p*10 + r->val;

        if(!r->left && !r->right)
            ans += num;

        dfs(r->left, ans,num);
        dfs(r->right, ans, num);
    }
};