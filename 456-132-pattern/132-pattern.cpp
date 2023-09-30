class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 30.09.23 potd
        // Approach: Reverse Traversal, Binary Search along with Stack usage

        stack<int> st;
        int third = INT_MIN;

        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] < third) return true;

            while(st.size() and st.top()<nums[i]){
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }
        return false;


        // APPROACH: Free-style, left-to-right linear search
        // if(nums.size()<3)   return false;

        // int left = nums[0], i=1, right=INT_MIN;
        // int leftIdx=0, rightIdx=-1;

        // while(i<nums.size()){
        //     if(i<nums.size()-2 and nums[i] <= left){
        //         left = nums[i];
        //         leftIdx = i;
        //     }
        //     else if(nums[i] > left){
        //         if(right < nums[i]){
        //             right=nums[i];
        //             rightIdx = i;
        //         }   
        //         else if(leftIdx < rightIdx and nums[i] < right)  return true;
        //     }

        //     i++;
        // }

        // return false;
    }
};