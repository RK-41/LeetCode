class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        // 13.02.24 POTD
        
        for(auto w: words){
            string s=w;
            reverse(s.begin(), s.end());
            if(s==w)
                return s;
        }

        return "";
    }
};