class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // 28.10.24 potd
        int ans = -1;
        map<int,int> mp;
        sort(nums.begin(), nums.end());

        for(int n: nums){
            int _sqrt = sqrt(n);
            if(_sqrt*_sqrt == n && mp.count(_sqrt)){
                mp[n] = mp[_sqrt]+1;
                ans = max(ans, mp[n]);
            } else {
                mp[n] = 1;
            }
        }

        return ans;
    }
};