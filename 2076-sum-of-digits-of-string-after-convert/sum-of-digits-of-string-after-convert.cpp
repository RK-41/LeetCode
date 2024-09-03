class Solution {
public:
    int getLucky(string s, int k) {
        // 03.09.24 POTD
        int ans=0;
        string t;

        for(auto c: s){
            t += to_string(c-'a'+1);
        }

        while(k--){
            ans = 0;
            for(auto c: t){
                ans += (c-'0');
            }
            t = to_string(ans);
        }

        return ans;
    }
};