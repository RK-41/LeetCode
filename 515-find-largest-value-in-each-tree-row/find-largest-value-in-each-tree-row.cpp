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
    vector<int> largestValues(TreeNode* root) {
        // 24.10.23 POTD
        // APPROACH: BFS Using Queue

        if(!root)   return {};
        
        vector<int> ans;
        queue<TreeNode*> q;

        q.push(root);
        while(q.size()){
            int breadth = q.size();
            int mx = INT_MIN;

            while(breadth--){
                auto node = q.front();
                q.pop();

                mx = max(mx, node->val);

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(mx);
        }
        return ans;
    }
};