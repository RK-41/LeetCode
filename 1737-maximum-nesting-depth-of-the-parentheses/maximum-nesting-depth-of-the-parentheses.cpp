class Solution {
public:
    int maxDepth(string s) {
        // 04.04.24 POTD
        if(s.size()==0)
            return 0;
        if(s.size()==1 && (s[0]!='(' && s[0]!=')'))
            return 0;

        int ans=0, n=s.size(), cnt=0;
        char prev='0';

        for(int i=0; i<n; i++){
            cnt += s[i]=='(' ? 1 : s[i]==')' ? -1 : 0;
            ans = max(ans, cnt);
        }

        return ans;
    }
};