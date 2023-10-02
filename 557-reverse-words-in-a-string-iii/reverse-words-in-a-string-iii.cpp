class Solution {
public:
    string reverseWords(string s) {
        // 01.10.23 POTD

        string t, ans;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' '){
                ans = t + " " + ans;
                t="";
            }
            else{
                t += s[i];
            }
        }

        ans = t + " " + ans;

        ans.pop_back();

        return ans;
    }
};