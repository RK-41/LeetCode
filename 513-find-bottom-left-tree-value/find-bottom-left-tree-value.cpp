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
    int findBottomLeftValue(TreeNode* root) {
        // 28.02.24 POTD
        int ans;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            int sz=q.size();
            int f=1;

            while(sz--){
                auto nd = q.front();
                q.pop();

                if(f){
                    ans = nd->val;
                    f = 0;
                }

                if(nd->left)    q.push(nd->left);
                if(nd->right)   q.push(nd->right);
            }
        }

        return ans;
    }
};