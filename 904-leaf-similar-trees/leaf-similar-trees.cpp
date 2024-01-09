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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // 09.01.24 POTD
        vector<int> leafSeq1, leafSeq2;

        leafSequencing(root1, leafSeq1);
        leafSequencing(root2, leafSeq2);

        return leafSeq1 == leafSeq2;
    }

    void leafSequencing(TreeNode* r, vector<int>& v){
        if(!r)  return;

        leafSequencing(r->left, v);
        
        if(!r->left && !r->right)
            v.push_back(r->val);
        
        leafSequencing(r->right, v);
    }
};