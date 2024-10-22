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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // 22.10.24 POTD
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            int sz = q.size();
            long long sum=0;

            while(sz--){
                auto t = q.front();
                q.pop();

                sum += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }

            pq.push(sum);
            if(pq.size() > k)   pq.pop();
        }

        return pq.size() == k ? pq.top() : -1;
    }
};