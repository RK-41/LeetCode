class Solution {
public:
    string reversePrefix(string word, char ch) {
        // 01.05.24 POTD
        string ans;
        int i=0;

        for(; i<word.size(); i++){
            ans = word[i] + ans;
            if(word[i] == ch){
                ans += word.substr(i+1);
                return ans;
            }
        }

        return word;
    }
};