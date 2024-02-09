class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 09.02.24 potd
        int n=nums.size(), mx=1, num=-1;
        vector<int> ans, dp(n,1);
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(!(nums[i]%nums[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    
                    if(mx<dp[i])
                        mx=dp[i];
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            if(mx==dp[i] && (num==-1 || !(num%nums[i]))){
                ans.push_back(nums[i]);
                mx--;
                num=nums[i];
            }
        }

        return ans;
    }
};