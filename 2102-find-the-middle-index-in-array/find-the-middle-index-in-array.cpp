class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // 23.09.23

        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        // Traversing the nums vector
        for(int i=0; i<nums.size(); i++){
            // Subtracting the current element from rightSum
            rightSum -= nums[i];

            // If leftSum == rightSum, return current index
            if(leftSum == rightSum)
                return i;

            // Adding current element to the leftSum
            leftSum += nums[i];
        }
            
        return -1;
    }
};