/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        // 27.08.24 (26.08.24 POTD)
        if(!root)   return {};
        vector<int> ans;
        vector<Node*>children = root->children;
        
        for(int i=0; i<children.size(); i++){
            vector<int> v = postorder(children[i]);

            for(int j=0; j<v.size(); j++){
                ans.push_back(v[j]);
            }
        }
        
        ans.push_back(root->val);
        return ans;
    }
};