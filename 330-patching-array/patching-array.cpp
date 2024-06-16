class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // 16.06.24 potd
        int ans = 0;
        long long miss = 1;
        size_t i = 0;

        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                ans++;
            }
        }

        return ans;
    }
};