class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 23.09.23

        int i=0, j=0, sum=0, ans=INT_MAX;

        while(true){
            if(sum<target and j<nums.size()){
                sum += nums[j];
                j++;
            }
            else if(sum<target and j>=nums.size()){
                break;
            }
            else if(sum >= target){
                sum -= nums[i];
                ans = min(ans, j-i);
                i++;
            }
        }

        if(i==0 and j>=0)   return 0;

        return ans;
    }
};