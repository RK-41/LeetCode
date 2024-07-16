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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // 16.07.24 potd
        vector<string> pathToStart, pathToDest;
        findPathFromRoot(root, startValue, pathToStart);
        findPathFromRoot(root, destValue, pathToDest);

        int commonPathLen = 0;
        while(commonPathLen < pathToStart.size() && commonPathLen < pathToDest.size() && pathToStart[commonPathLen] == pathToDest[commonPathLen]){
            commonPathLen++;
        }

        vector<string> dir(pathToStart.size() - commonPathLen, "U");
        dir.insert(dir.end(), pathToDest.begin() + commonPathLen, pathToDest.end());

        string ans;
        for(const auto& d: dir){
            ans += d;
        }

        return ans;
    }

private:
    bool findPathFromRoot(TreeNode* node, int targetVal, vector<string>& pathToAppend){
        if(!node)
            return false;

        if(node->val == targetVal)
            return true;

        pathToAppend.push_back("R");
        if(findPathFromRoot(node->right, targetVal, pathToAppend))
            return true;

        pathToAppend.pop_back();

        pathToAppend.push_back("L");
        if(findPathFromRoot(node->left, targetVal, pathToAppend))
            return true;

        pathToAppend.pop_back();

        return false;
    }
};