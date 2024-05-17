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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // 17.05.24 POTD
        if(!root)   return root;

        removeLeafNodes(root->left, target);
        removeLeafNodes(root->right, target);

        if(root->left && !root->left->left && !root->left->right && root->left->val==target){
            root->left = NULL;
        }
        if(root->right && !root->right->left && !root->right->right && root->right->val==target){
            root->right = NULL;
        }
        
        if(!root->left && !root->right && root->val == target)
            return NULL;
        
        return root;
    }
};