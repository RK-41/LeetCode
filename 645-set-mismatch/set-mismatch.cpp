class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 22.01.24 POTD
        vector<int> ans;
        int idealSum=0, actualSum=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0)
                ans.push_back(abs(nums[i]));

            nums[abs(nums[i])-1] *= (-1);
            idealSum += (i+1);
            actualSum += abs(nums[i]);
        }

        int missing = idealSum - (actualSum - ans[0]);
        ans.push_back(missing);

        return ans;
    }
};