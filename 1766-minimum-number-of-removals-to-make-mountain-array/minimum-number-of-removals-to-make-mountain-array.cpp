class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // 30.10.24 potd
        int n = nums.size(), mxLen = 0;
        vector<int> LIS(n, 1), LDS(n, 1);

        // Compute LIS up to each idx
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j])
                    LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }

        // Compute LDS from each idx
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(nums[i] > nums[j])
                    LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }

        // Find the max mountain len
        for(int i=1; i<n-1; i++){
            if(LIS[i] > 1 && LDS[i] > 1){   // Valid peak
                mxLen = max(mxLen, LIS[i] + LDS[i] - 1);
            }
        }

        return n - mxLen;
    }
};