class Solution {
public:
    const int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        // 26.10.23 potd
        // Approach: DP

        sort(arr.begin(), arr.end());
        unordered_set<int> st(arr.begin(), arr.end());
        unordered_map<int,int> dp;

        for(int x: arr)     dp[x] = 1;

        for(int i: arr){
            for(int j: arr){
                if(j > sqrt(i)) break;

                if(i%j == 0 and st.find(i/j) != st.end()){
                    long long temp = (long long)dp[j] * dp[i/j];

                    if(i/j == j){
                        dp[i] = (dp[i]+temp)%MOD;
                    } else {
                        dp[i] = (dp[i]+temp*2)%MOD;
                    }
                }
            }
        }

        int res = 0;
        for(auto& [_, val]: dp){
            res = (res + val)%MOD;
        }

        return res;
    }
};