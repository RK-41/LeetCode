class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // 22.11.25 POTD
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%3 != 0)
                ans++;
        }

        return ans;
    }
};