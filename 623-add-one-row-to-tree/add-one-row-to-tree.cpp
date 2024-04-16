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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // 16.04.24 POTD
        if(depth==1 && root){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root,1});

        while(q.size()){
            auto d=q.front().second;
            if(d == depth)  break;

            auto curr=q.front().first;
            q.pop();

            if(d == depth-1){
                TreeNode* newL = new TreeNode(val);
                TreeNode* newR = new TreeNode(val);
                newL->left = curr->left;
                newR->right = curr->right;

                curr->left = newL;
                curr->right = newR;
            }
                
            if(curr->left)  
                q.push({curr->left, d+1});
            if(curr->right)
                q.push({curr->right, d+1});            
        }

        return root;
    }
};