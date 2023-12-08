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
    string tree2str(TreeNode* root) {
        // 08.12.23 POTD
        string ans;
        dfs(root, ans);

        return ans;
    }

    void dfs(TreeNode* r, string& s){
        if(!r)  return;

        s += to_string(r->val);

        if(!r->left && !r->right)   return;

        s += '(';
        dfs(r->left, s);
        s += ')';

        if(r->right){
            s += '(';
            dfs(r->right, s);
            s += ')';
        }
    }
};