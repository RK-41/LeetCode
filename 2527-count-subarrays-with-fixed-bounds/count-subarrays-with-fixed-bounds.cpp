class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // 31.03.24 potd
        long long ans=0;
        int badIdx=-1, leftIdx=-1, rightIdx=-1;

        for(int i=0; i<nums.size(); i++){
            if(!(minK <= nums[i] && nums[i] <= maxK)){
                badIdx = i;
            }

            if(nums[i] == minK){
                leftIdx = i;
            }

            if(nums[i] == maxK){
                rightIdx = i;
            }

            ans += max(0, min(leftIdx, rightIdx) - badIdx);
        }

        return ans;
    }
};