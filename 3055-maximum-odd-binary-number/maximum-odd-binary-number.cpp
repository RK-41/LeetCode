class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // 01.03.24 pOTD

        // APPROACH 1: Time consuming
        // string ans="";
        // for(int i=0; i<s.size(); i++){
        //     if(s[i]=='1')
        //         ans = "1"+ans;
        //     else
        //         ans = ans+"0";
        // }
        // ans = ans.substr(1) + "1";

        // Approach 2:
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());

        s = s.substr(1) + "1";
        return s;
    }
};