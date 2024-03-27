class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 27.03.24 potd
        if(k<=1)    return 0;

        int left=0, right=0, prod=1, ans=0;
        int n=nums.size();
        
        while(right<n){
            prod *= nums[right];
            while(prod >= k)
                prod /= nums[left++];

            ans += 1 + (right-left);
            right++;
        }

        return ans;
    }
};