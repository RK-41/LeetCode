class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // 01.05.26 potd
        int ans, sum = 0, F = 0, n = nums.size();

        for(int i=0; i<n; i++){
            sum += nums[i];
            F += i * nums[i];
        }

        ans = F;

        for(int i=1; i<n; i++){
            F += sum - n * nums[n-i];
            ans = max(ans, F);
        }

        return ans;
    }
};