class Solution {
public:
    int minLength(string s) {
        // 07.10.24 POTD
        int ans=s.size(), n=s.size();
        
        for(int i=1; i<n; i++){
            if((s[i-1] == 'A' && s[i] == 'B') || (s[i-1] == 'C' && s[i] == 'D')){
                int len = minLength(s.substr(0,i-1) + s.substr(i+1));
                ans = min(ans, len);
                break;
            }
        }

        return ans;
    }
};