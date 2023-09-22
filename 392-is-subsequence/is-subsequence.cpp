class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 22.09.23 POTD

        int i=0, j=0;

        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++, j++;
            }
            else
                j++;
        }

        if(i==s.size())
            return true;

        return false;
    }
};