class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // 01.02.24 potd
        int n=nums.size(), grIdx=0;
        vector<vector<int>> ans(n/3, vector<int>(3));
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i+=3){
            if(i+2 < n && nums[i+2]-nums[i] <= k){
                ans[grIdx] = {nums[i], nums[i+1], nums[i+2]};
                grIdx++;
            } else {
                return vector<vector<int>>();
            }
        }

        return ans;
    }
};