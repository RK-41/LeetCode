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
    unordered_map<int, vector<int>> graph;
    int amountOfTime(TreeNode* root, int start) {
        // 10.01.24 potd
        // Good problem and easily understandable solution.
        constructGraph(root);

        queue<int> q;
        int minPassed=-1;
        unordered_set<int> vis;

        q.push(start);

        while(q.size()){
            ++minPassed;

            for(int levelSize=q.size(); levelSize>0; --levelSize){
                int currNode=q.front();
                q.pop();
                vis.insert(currNode);

                for(int adjNode: graph[currNode]){
                    if(!vis.count(adjNode)){
                        q.push(adjNode);
                    }
                }
            }
        }

        return minPassed;
    }

    void constructGraph(TreeNode* root){
        if(!root)   return;

        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
};