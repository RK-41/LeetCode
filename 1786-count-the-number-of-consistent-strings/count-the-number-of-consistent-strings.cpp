class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // 12.09.24 POTD
        int ans = words.size();
        unordered_set<char> st = {allowed.begin(), allowed.end()};

        for(string w: words){
            for(char c: w){
                if(!st.count(c)){
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};