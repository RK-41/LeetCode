class Solution {
public:
    int maxScore(string s) {
        // 22.12.23 POTD
        int ans=0, n=s.size();
        vector<int> zeroCount(n), oneCount(n);
        zeroCount[0] = '1'-s[0];
        oneCount[n-1] = s[n-1]-'0';
        for(int i=1; i<n; i++){
            zeroCount[i] = '1'-s[i]+zeroCount[i-1];
            oneCount[n-1-i] = s[n-1-i]-'0'+oneCount[n-i];
        }

        for(int i=1; i<n; i++){
            ans = max(ans, zeroCount[i-1]+oneCount[i]);
        }

        return ans;
    }
};