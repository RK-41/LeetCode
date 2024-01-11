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
    int maxAncestorDiff(TreeNode* root) {
        // 11.01.24 POTD
        int ans=0, mx=root->val, mn=root->val;

        findMaxDiff(root, ans, mx, mn);
        return ans;
    }

    void findMaxDiff(TreeNode* r, int& ans, int& mx, int& mn){
        if(!r)  return;

        int newmx = max(mx, r->val);
        int newmn = min(mn, r->val);
        ans = max(ans, abs(mx-r->val));
        ans = max(ans, abs(mn-r->val));
        // ans = max(ans, abs(newmn-r->val));

        findMaxDiff(r->left, ans, newmx, newmn);
        findMaxDiff(r->right, ans, newmx, newmn);
    }
};