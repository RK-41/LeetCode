class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // 19.05.24 potd
        long long totalSum = accumulate(nums.begin(), nums.end(), 0ll);
        long long totalDiff = 0;
        long long diff;
        int positiveCount = 0;
        long long minAbsDiff = numeric_limits<int>::max();

        for(auto p: nums){
            diff = (p^k) - p;

            if(diff>0){
                totalDiff += diff;
                positiveCount++;
            }

            minAbsDiff = min(minAbsDiff, abs(diff));
        }

        if(positiveCount%2 == 1){
            totalDiff = totalDiff - minAbsDiff;
        }

        return totalSum + totalDiff;
    }
};