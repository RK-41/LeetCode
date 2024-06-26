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
    TreeNode* balanceBST(TreeNode* root) {
        // 26.06.24 potd
        vector<int> sortedEle;
        inOrderTrav(root, sortedEle);

        return buildBalancedBST(sortedEle, 0, sortedEle.size()-1);
    }

private:
    void inOrderTrav(TreeNode* r, vector<int>& v){
        if(!r)  return;

        inOrderTrav(r->left, v);
        v.push_back(r->val);
        inOrderTrav(r->right, v);
    }

    TreeNode* buildBalancedBST(const vector<int>& v, int start, int end){
        if(start > end) return nullptr;

        int mid = start + (end-start)/2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = buildBalancedBST(v, start, mid-1);
        node->right = buildBalancedBST(v, mid+1, end);

        return node;
    }
};