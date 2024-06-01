class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 01.06.24
        int ans=INT_MIN, sum=0;

        for(auto a: nums){
            sum += a;
            ans = max(ans, sum);

            if(sum <= 0){
                sum = 0;
            }
        }

        return ans;
    }
};