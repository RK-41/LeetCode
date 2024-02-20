class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 20.02.24 POTD
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long properSum = ((nums.size())*(nums.size()+1))/2;

        return (int)(properSum - sum);
    }
};