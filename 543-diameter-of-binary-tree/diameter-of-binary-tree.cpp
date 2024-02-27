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
    int diameterOfBinaryTree(TreeNode* root) {
        // 27.02.24 POTD
        if(!root)   return 0;

        int ans=0;
        findDiameter(root, ans);

        return ans;
    }

    int findDiameter(TreeNode* r, int& ans){
        if(!r)  return 0;
        if(!r->left && !r->right)
            return 1;

        int left = findDiameter(r->left, ans);
        int right = findDiameter(r->right, ans);

        ans = max(ans, left+right);
        return max(left, right) + 1;
    }
};