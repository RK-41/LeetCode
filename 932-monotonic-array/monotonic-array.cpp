class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // 29.09.23 POTD

        int count=1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]<=nums[i])
                count++;
        }

        if(count==nums.size())  return true;

        count=1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]>=nums[i])
                count++;
        }

        if(count==nums.size())  return true;

        return false;
    }
};