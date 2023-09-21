class Solution {
public:
    int rob(vector<int>& nums) {
        // 21.09.23
        if(nums.size()==1)
            return nums[0];

        int n = nums.size();
        nums[n-2] = max(nums[n-1],nums[n-2]);

        // Traversing 'nums' from end to beginning and,
        // finding max amount of money between (current house plus current+2 house) and (current+1 house)
        // and storing it in the current house
        for(int i{n-3}; i>=0; i--){
            nums[i] = max(nums[i]+nums[i+2], nums[i+1]);
        }

        // The first house would have the max amount of money
        return nums[0];
    }
};