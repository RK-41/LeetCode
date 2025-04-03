class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // 03.04.25 potd
        int n = nums.size();
        if(n < 3)  return 0;

        long long ans = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);

        leftMax[0] = nums[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], nums[i]);
        }

        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        for(int i=1; i<n-1; i++){
            int left = leftMax[i-1], right = rightMax[i+1];
            ans = max(ans, (long long)(left - nums[i]) * right);
        }

        return ans;
    }
};