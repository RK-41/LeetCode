class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // 14.09.24 potd
        int n=nums.size(), ans=1, tempLen=0;
        int mx = *max_element(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i] == mx){
                tempLen++;
            } else {
                ans = max(ans, tempLen);
                tempLen = 0;
            }
        }

        ans = max(ans, tempLen);

        return ans;
    }
};