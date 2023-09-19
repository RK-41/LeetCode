class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 19.09.23 POTD
        // int ans;
        
        for(auto n: nums){
            nums[abs(n)]*=-1;
            if(nums[abs(n)] > 0){
                nums[0] = abs(n);
                break;
            }
        }

        return nums[0];
    }
};