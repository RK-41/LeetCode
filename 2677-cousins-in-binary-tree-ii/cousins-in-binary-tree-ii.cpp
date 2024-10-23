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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // 23.10.24 potd
        root->val = 0;
        bfs(std::vector<TreeNode*>{root});

        return root;
    }

private:
    void bfs(std::vector<TreeNode*> arr){
        if(arr.empty()) return;

        int sum=0;
        for(auto nd: arr){
            if(!nd) continue;
            if(nd->left)    sum += nd->left->val;
            if(nd->right)   sum += nd->right->val;
        }
        
        std::vector<TreeNode*> childArr;
        for(auto nd: arr){
            int currSum=0;
            if(nd->left)    currSum += nd->left->val;
            if(nd->right)   currSum += nd->right->val;

            if(nd->left){
                nd->left->val = sum - currSum;
                childArr.push_back(nd->left);
            }
            if(nd->right){
                nd->right->val = sum - currSum;
                childArr.push_back(nd->right);
            }
        }

        bfs(childArr);
    }
};