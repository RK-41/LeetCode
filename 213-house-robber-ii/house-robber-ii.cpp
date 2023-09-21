class Solution {
public:
    int rob(vector<int>& nums) {
        // 21.09.23

        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);

        vector<int> a(nums.begin()+1, nums.end());
        vector<int> b(nums.begin(), nums.end()-1);

        return max(buddy(a), buddy(b));
    }

    // A helper function
    int buddy(vector<int> &v){
        vector<int> dp(v.size());

        dp[0] = v[0];
        dp[1] = max(v[0], v[1]);

        for(int i=2; i<v.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+v[i]);
        }

        return dp.back();
    }
};