class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 25.05.24 POTD
        vector<string> ans;
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        solve(ans, st, s, "");
        return ans;
    }

    void solve(vector<string>& ans, unordered_set<string>& st, string s, string sent){
        if(s.size() == 0){
            ans.push_back(sent);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string w = s.substr(0, i+1);

            if(st.find(w) != st.end()){
                string new_sent;

                if(sent == "")
                    new_sent = w;
                else
                    new_sent = sent+" "+w;

                string new_s = s.substr(i+1);

                solve(ans, st, new_s, new_sent);
            }
        }
    }
};