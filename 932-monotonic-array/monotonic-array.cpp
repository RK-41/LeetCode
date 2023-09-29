class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // 29.09.23 POTD

        int inc=1, dec=1;;

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]<=nums[i])
                inc++;
            if(nums[i-1]>=nums[i])
                dec++;
        }

        if(inc==nums.size() || dec==nums.size())    return true;

        return false;
    }
};