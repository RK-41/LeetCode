class Solution {
public:
    int minimumDeletions(string s) {
        // 30.07.24 potd
        int ans=0, n=s.size(), b=0;
        int f[n+1];
        memset(f, 0, sizeof(f));

        for(int i=1; i<=n; i++){
            if(s[i-1]=='b'){
                f[i] = f[i-1];
                ++b;
            } else {
                f[i] = min(f[i-1]+1, b);
            }
        }
        
        return f[n];
    }
};