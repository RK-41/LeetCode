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
    int countPairs(TreeNode* root, int distance) {
        // 18.07.24 potd
        int ans=0;
        unordered_map<TreeNode*, vector<TreeNode*>> um;
        vector<TreeNode*> leaves;
        
        findLeaves(root, {}, leaves, um);

        for(int i=0; i<leaves.size(); i++){
            for(int j=i+1; j<leaves.size(); j++){
                vector<TreeNode*>& list_i = um[leaves[i]];
                vector<TreeNode*>& list_j = um[leaves[j]];

                for(int k=0; k < min(list_i.size(), list_j.size()); k++){
                    if(list_i[k] != list_j[k]){
                        int dist = list_i.size() - k + list_j.size() - k;
                        if(dist <= distance)
                            ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }

private:
    void findLeaves(TreeNode* node, vector<TreeNode*> trail, vector<TreeNode*>& leaves, unordered_map<TreeNode*, vector<TreeNode*>>& um){
        if(!node)   return;

        vector<TreeNode*> tmp(trail);
        tmp.push_back(node);

        if(!node->left && !node->right){
            um[node] = tmp;
            leaves.push_back(node);

            return;
        }

        findLeaves(node->left, tmp, leaves, um);
        findLeaves(node->right, tmp, leaves, um);
    }
};