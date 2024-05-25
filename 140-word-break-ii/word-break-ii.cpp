class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 25.05.24
        vector<string> ans;
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        solve(ans, st, s, "", 0);
        return ans;

        // int idx=0, count=0;
        // // string w = s.substr(0,1), sent;
        // string w="", sent;

        // for(int i=0; i<s.size(); i++){
        //     w += s[i];

        //     if(st.find(w) != st.end()){
        //         cout<<w<<" "<<i<<endl;
        //         sent = w + " ";
        //         count = 1;
        //         find(ans, st, s, sent, i+1, count);
        //     }
        // }

        // if(ans.empty() && st.find(w) != st.end())
        //     ans.push_back(w);

        // return ans;
    }

    void solve(vector<string>& ans, unordered_set<string>& st, string s, string sent, int idx){
        if(s.size() == 0){
            cout<<"*"<<sent<<endl;
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
                cout<<w<<" "<<new_s<<" "<<sent<<endl;

                solve(ans, st, new_s, new_sent, i+1);
            }
        }
    }

    void find(vector<string>& ans, unordered_set<string>& st, string& s, string sent, int idx, int count){
        if(idx >= s.size()) return;
        cout<<"*"<<sent<<count<<endl;
        string sentence = sent;
        string temp = sent;

        for(int i=idx; i<s.size(); i++){
            string w = s.substr(idx, i-idx+1);

            if(st.find(w) != st.end()){
                cout<<"**"<<sent<<idx<<endl;
                sentence = sent + w + " ";
                cout<<w<<" "<<i<<" "<<sentence<<endl;
                count++;
                find(ans, st, s, sent + w + " ", i+1, count);
            if(i == s.size()-1)
                sent += w;
                cout<<"$"<<sent<<"; "<<w<<endl;
    
                if(sent.size() >= s.size()){
                    // sent.pop_back();
                    cout<<sent<<"\n\n";
                    ans.push_back(sent);
                }
            }

            // sent = sentence;
        }
        
        cout<<"#"<<temp<<count<<" "<<idx<<endl;

        return;
    }
};