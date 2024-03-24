class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 24.03.24 (POTD)
        
        for(auto n: nums){
            nums[abs(n)]*=-1;
            if(nums[abs(n)] > 0){
                return abs(n);
            }
        }

        return 0;
    }
};