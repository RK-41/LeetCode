class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 22.01.24 POTD
        vector<int> ans;
        int idealSum=0, actualSum=accumulate(nums.begin(), nums.end(), 0);

        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0)
                ans.push_back(abs(nums[i]));

            nums[abs(nums[i])-1] *= (-1);
            idealSum += (i+1);
        }

        int missing = idealSum - (actualSum - ans[0]);
        ans.push_back(missing);

        return ans;
    }
};