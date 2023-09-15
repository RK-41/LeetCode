class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 15.09.23
        // APPROACH: Dynamic Programming

        // Step 1: Finding sum of array elements
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum); 
        // header file for accumulate(): 'numeric'

        // Step 2: Odd sum check
        // It's impossible to partition array into two equal parts with odd sum.
        if(sum%2 == 1)
            return false;

        // Step 3: DP Vector initialization
        vector<int> dp(sum+1, 0);

        // A sum of '0' can be achieved using an empty sub-array
        dp[0] = 1;

        // Step 4: DP Loop
        // Iterating through the array 'nums'. For every element, the 'dp' vector 
        // is traversed in reverse order from 'sum/2' to 'nums[i-1]'
        // 'dp[j]' is updated if it's a sum of 'j' is achievable with current 
        // element 'nums[i-1]'

        for(int i=1; i<=nums.size(); i++){
            for(int j=sum/2; j>=nums[i-1]; j--){
                // if nums[i-1] <= j, it can either be considered or skipped
                
                // dp[j] is updated to true if sum 'j-nums[i-1]' can be 
                // formed with previous elements
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }

        // Step 5: Returning the result
        // If dp[sum/2] is true, it means that the array can be parititioned into two
        // parts of equal sum.
        // Otherwise, it's not possible to do so.
        return dp[sum/2];
    }
};