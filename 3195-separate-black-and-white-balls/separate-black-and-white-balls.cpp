class Solution {
public:
    long long minimumSteps(string s) {
        // 15.10.24 potd
        long long ans=0;
        int black=0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') ans += (long long) black;
            else    black++;
        }

        return ans;
    }
};