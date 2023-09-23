class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        // Traverse all elements through the loop
        for(int i=0; i<nums.size(); i++){
            // subtract current element from rightSum
            rightSum -= nums[i];

            // If the sum of all the numbers strictly to the left of the current
            //  index is equal to the sum of all the numbers strictly to the right
            //  of the current index
            if(leftSum == rightSum)
                return i;
            
            // Add current element to the leftSum
            leftSum += nums[i];
        }

        return -1;
    }
};