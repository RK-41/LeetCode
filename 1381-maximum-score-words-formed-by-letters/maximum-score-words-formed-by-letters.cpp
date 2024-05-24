class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // 24.05.24 potd
        int ans=0;
        vector<int> count(26,0), lettersCount(26,0);

        for(auto &c: letters){
            count[c-'a']++;
        }

        backtrack(words, score, count, lettersCount, 0, 0, ans);

        return ans;
    }

    void backtrack(vector<string>& words, vector<int>& score, vector<int>& count, vector<int>& lettersCount, int pos, int temp, int& ans){
        for(int i=0; i<26; i++){
            if(lettersCount[i] > count[i])
                return;
        }
        
        ans = max(ans, temp);
        
        for(int i=pos; i<words.size(); i++){
            for(auto& c: words[i]){
                lettersCount[c-'a']++;
                temp += score[c-'a'];
            }

            backtrack(words, score, count, lettersCount, i+1, temp, ans);

            for(auto& c: words[i]){
                lettersCount[c-'a']--;
                temp -= score[c-'a'];
            }
        }
    }
};