class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 02.03.24 POTD
        vector<int> ans;
        for(auto n: nums){
            ans.push_back(n*n);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};