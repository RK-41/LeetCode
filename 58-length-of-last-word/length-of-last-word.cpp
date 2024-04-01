class Solution {
public:
    int lengthOfLastWord(string s) {
        // 01.04.24 POTD
        int ans=0, i=s.size()-1;

        while(i >= 0 && s[i] == ' '){
            i--;
        }

        while(i >= 0 && s[i] != ' '){
            i--;
            ans++;
        }

        return ans;
    }
};