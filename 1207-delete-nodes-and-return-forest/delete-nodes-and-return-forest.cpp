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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // 17.07.24 POTD
        // KEY IDEA: DFS BACKTRACK
        vector<TreeNode*> forest;
        set<int> toDelete = {to_delete.begin(), to_delete.end()};

        dfs(root, forest, toDelete);

        if(!toDelete.count(root->val))
            forest.push_back(root);

        return forest;
    }

    void dfs(TreeNode* node, vector<TreeNode*>& forest, set<int>& toDel){
        if(!node){
            return;
        }

        dfs(node->left, forest, toDel);
        dfs(node->right, forest, toDel);

        if(toDel.count(node->val)){
            if(node->left && !toDel.count(node->left->val))
                forest.push_back(node->left);
            if(node->right && !toDel.count(node->right->val))
                forest.push_back(node->right);
        }

        if(node->left && toDel.count(node->left->val)){
            node->left = NULL;
        }

        if(node->right && toDel.count(node->right->val)){
            node->right = NULL;
        }
    }
};