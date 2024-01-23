class Solution {
public:
    int maxLength(vector<string>& arr) {
        // 23.01.24 potd

        vector<int> dp={0};
        int ans=0;

        for(const string& s: arr){
            int a=0, dup=0;
            for(char c: s){
                dup |= a & (1<<(c-'a'));
                a |= 1<<(c-'a');
            }

            if(dup>0)   
                continue;

            for(int i=dp.size()-1; i>=0; i--){
                if((dp[i] & a)>0)
                    continue;

                dp.push_back(dp[i] | a);
                ans = max(ans, __builtin_popcount(dp[i] | a));
            }
        }

        return ans;
    }
};