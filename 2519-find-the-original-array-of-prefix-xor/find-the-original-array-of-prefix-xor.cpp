class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // 31.10.23 POTD
        int n = pref.size();
        vector<int> ans(n);

        ans[0] = pref[0];
        int xr = pref[0];

        for(int i=1; i<n; i++){
            xr ^= pref[i];
            ans[i] = xr;
            xr = pref[i];
        }

        return ans;
    }
};