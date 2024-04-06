class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // 06.04.24 POTD
        string ans;
        int n=s.size(), cnt=0;
        vector<int> closeCnt(n,0);

        closeCnt[n-1] = s[n-1]==')' ? 1:0;
        for(int i=s.size()-2; i>=0; i--){
            closeCnt[i] += closeCnt[i+1] + (s[i]==')' ? 1:0);
        }
        
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(closeCnt[i]>cnt){
                    ans += s[i];
                    cnt++;
                }
            } else if(s[i]==')'){
                if(cnt>0){
                    ans += s[i];
                    cnt--;
                }
            } else{
                ans += s[i];
            }
        }

        return ans;
    }
};