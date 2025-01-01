class Solution {
public:
    int maxScore(string s) {
        // 01.01.25 POTD
        int ans=0, n=s.size();
        int oneCount = 0, zeroCount = '1'-s[0];

        for(int i=n-1; i>0; i--){
            oneCount += s[i]-'0';
        }

        for(int i=1; i<n; i++){
            ans = max(ans, zeroCount + oneCount);
            oneCount -= (s[i]-'0');
            zeroCount += ('1'-s[i]);
        }

        return ans;
    }
};