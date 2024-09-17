class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // 17.09.24 POTD
        vector<string> ans;
        unordered_map<string,int> words;
        string word;

        for(auto c: s1){
            if(c == ' '){
                words[word]++;
                word = "";
            } else {
                word += c;
            }
        }

        words[word]++;
        word = "";

        for(auto c: s2){
            if(c == ' '){
                words[word]++;
                word = "";
            } else {
                word += c;
            }
        }

        words[word]++;

        for(auto w: words){
            if(w.second == 1)   
                ans.push_back(w.first);
        }

        return ans;
    }
};