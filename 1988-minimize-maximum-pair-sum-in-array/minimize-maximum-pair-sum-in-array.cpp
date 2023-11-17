class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // 17.11.23 POTD

        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n/2; i++){
            ans = max(ans, nums[i]+nums[n-1-i]);
        }

        return ans;
    }
};