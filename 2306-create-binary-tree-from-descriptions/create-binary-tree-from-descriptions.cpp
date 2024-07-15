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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // 15.07.24 POTD
        TreeNode* head;
        set<TreeNode*> parents, children;
        unordered_map<int,TreeNode*> vis;
        
        for(auto d: descriptions){
            TreeNode* p, *c;

            if(vis.count(d[0])){
                p = vis[d[0]];
            }
            else{
                p = new TreeNode(d[0]);
                vis[d[0]] = p;
            }
            
            if(vis.count(d[1])){
                c = vis[d[1]];
            }
            else{
                c = new TreeNode(d[1]);
                vis[d[1]] = c;
            }

            d[2] == 1 ? p->left = c : p->right = c;

            parents.insert(p);
            parents.erase(c);
            children.insert(c);
        }

        for(auto x: parents){
            if(!children.count(x)){
                head = x;
                break;
            }
        }

        return head;
    }
};