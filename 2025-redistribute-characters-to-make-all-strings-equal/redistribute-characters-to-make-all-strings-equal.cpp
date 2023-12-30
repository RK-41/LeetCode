class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // 30.12.23 potd
        if(words.size() == 1){
            return true;
        }

        int charCount=0;
        for(const string& s: words){
            charCount += s.size();
        }
        if(charCount%words.size() != 0){
            return false;
        }

        vector<int> map(26,0);
        for(const string& s: words){
            for(char c: s){
                map[c-'a']++;
            }
        }

        for(int i: map){
            if(i%words.size() != 0){
                return false;
            }
        }

        return true;
    }
};