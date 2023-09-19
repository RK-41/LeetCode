class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 19.09.23 POTD
        int ans;
        
        for(auto n: nums){
            nums[abs(n)]*=-1;
            if(nums[abs(n)] > 0){
                ans = abs(n);
                break;
            }
        }

        return ans;
    }
};