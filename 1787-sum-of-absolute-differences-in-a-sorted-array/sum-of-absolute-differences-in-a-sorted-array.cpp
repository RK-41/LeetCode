class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // 25.11.23 potd
        vector<int> ans(nums.size(), 0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0, right = sum;

        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            right -= n;

            ans[i] = n * i - left + right - n * (nums.size()-1-i);

            left += n;
        }
        return ans;
    }
};