class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // 03.02.26 POTD
        int p=1, q=2, n=nums.size();
        if(nums[0] >= nums[1] || n == 3)  return false;

        while(p < n && nums[p-1] < nums[p]){
            p++;
        }

        if(p >= n-1)    return false;

        while(p < n && nums[p-1] > nums[p]){
            p++;
        }

        if(p == n)    return false;

        while(p < n && nums[p-1] < nums[p]){
            p++;
        }

        if(p < n)   return false;

        return true;
    }
};