class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // 06.10.24 POtd
        auto splitWords = [](const string& sentence){
            vector<string> words;
            string s;
            for(auto c: sentence){
                if(c == ' '){
                    if(!s.empty()){
                        words.push_back(s);
                        s = "";
                    }
                } else {
                    s += c;
                }
            }
            if(!s.empty())
                words.push_back(s);

            return words;
        };
        
        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        if(words1.size() < words2.size())   swap(words1, words2);

        int start = 0, end = 0, n1 = words1.size(), n2 = words2.size();

        while(start < n2 && words1[start] == words2[start])  start++;
        while(end < n2 && words1[n1-1-end] == words2[n2-1-end]) end++;

        return start + end >= n2;
    }
};