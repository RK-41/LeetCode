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
    string smallestFromLeaf(TreeNode* root) {
        // 17.04.24 POTD
        string ans;
        dfs(root, ans, "");

        return ans;
    }

    void dfs(TreeNode* r, string &ans, string prev){
        if(!r)  return;

        string s(1, r->val+97);
        s += prev;
        cout<<s<<" ";

        if(!r->left && !r->right){
            if(ans == "")
                ans = s;
            else
                ans = min(ans, s);
        }

        dfs(r->left, ans, s);
        dfs(r->right, ans, s);
    }
};