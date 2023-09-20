class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 20.09.23 potd
        // Approach: Sliding Window with Prefix Sum
        //  Two pointers are used - 'left' and 'right', to traverse the array 'nums' and find the 
        //      longest subarray whose sum equals the total sum of elements in 'nums' minus 'x'.

        // Key Data Structures:
        //  max_len: An int to store the len of the longest subarray that can be excluded to
        //      make the sum equal to 'x'.
        // cur_sum: An int to store the sum of elements in the current subarray.

        int target = 0, n = nums.size();

        // Step 1: Initialize and Calculate the Target
        for(int num: nums){
            target += num;
        }   

        target -= x;

        // Step 2: Check for edge cases:
        //  If target is zero, it means we need to remove all elements to make the sum equal to 'x'. 
        //  In this case, return the total no. of elements 'n'.
        if(target == 0) return n;

        // Step 3: Initialize max_len, cur_sum, and left to 0
        int max_len = 0, cur_sum = 0, left = 0;

        // Step 4: Traverse the array with two pointers
        for(int right=0; right<n; right++){
            // Update cur_sum by adding the current element nums[right]
            cur_sum += nums[right];

            // If 'cur_sum' exceeds the 'target', slide the 'left' pointer to the right by one 
            //  position and decrese the 'cur_sum' by 'nums[left]'
            while(left <= right && cur_sum > target){
                cur_sum -= nums[left];
                left++;
            }

            // Update Max Length:
            //  If the 'cur_sum' matches 'target', update 'max_len' with the length of the 
            //      current subarray, which is 'right-left+1'
            if(cur_sum == target){
                max_len = max(max_len, right-left+1);
            }
        }

        // Step 5: Conclude and Return:
        //  After the loop, if 'max_len' is non-zero, return 'n-max_len'.
        //  Otherwise, return -1, indicating it's not possibel to reduce x to zero.
        return max_len ? n-max_len : -1;
    }
};