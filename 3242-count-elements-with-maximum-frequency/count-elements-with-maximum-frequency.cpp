class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // 08.03.24 POTD
        int ans=0, mx=0;
        unordered_map<int,int> fr;

        for(auto n: nums){
            fr[n]++;
            mx = max(mx, fr[n]);
        }

        for(auto f: fr){
            ans += (f.second == mx);
        }

        return ans*mx;
    }
};