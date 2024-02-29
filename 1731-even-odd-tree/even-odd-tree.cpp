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
    bool isEvenOddTree(TreeNode* root) {
        // 29.02.24 POTD
        queue<TreeNode*> q;
        int level=0, prev=0;
        q.push(root);

        while(q.size()){
            int sz=q.size();

            while(sz--){
                auto nd=q.front();
                q.pop();

                if(level%2==0){
                    if(nd->val%2==0 || prev >= nd->val)
                        return false;
                } else {
                    if(nd->val%2==1 || prev <= nd->val)
                        return false;
                }
            
                prev = nd->val;
                
                if(nd->left)    q.push(nd->left);
                if(nd->right)   q.push(nd->right);
            }

            level++;
            level%2==0 ? prev=0 : prev=INT_MAX;
        }

        return true;
    }
};