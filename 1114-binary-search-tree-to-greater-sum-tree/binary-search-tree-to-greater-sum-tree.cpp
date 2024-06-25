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
    TreeNode* bstToGst(TreeNode* root) {
        // 25.06.24 POTD
        TreeNode* gst = root;
        int sum = 0;

        solve(gst, sum);
        return gst;
    }

    void solve(TreeNode* r, int& sum){
        if(!r)  return;

        solve(r->right, sum);

        r->val += sum;
        sum = r->val;

        solve(r->left, sum);
    }
};