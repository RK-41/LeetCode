class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 02.06.24
        // Approach: Recursion - Pick & Not Pick
        vector<vector<int>> ans;
        vector<int> comb;

        solve(0, candidates, target, comb, ans);

        return ans;
    }

    void solve(int i, vector<int>& candidates, int target, vector<int> comb, vector<vector<int>>& ans){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(comb);
            }

            return;
        }

        // Picking the element at index 'i'
        if(candidates[i] <= target){
            comb.push_back(candidates[i]);
            solve(i, candidates, target-candidates[i], comb, ans);
            comb.pop_back();
        }

        // Not picking the element at index 'i'
        solve(i+1, candidates, target, comb, ans);
    }
};