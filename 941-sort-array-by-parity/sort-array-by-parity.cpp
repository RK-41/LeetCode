class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // 28.09.23

        int i=0, j=nums.size()-1;

        while(true){
            while(i<nums.size()-1 and nums[i]%2==0) i++;
            while(j>0 and nums[j]%2==1) j--;

            if(i<j) swap(nums[i], nums[j]);
            else    break;
        }

        return nums;
    }
};