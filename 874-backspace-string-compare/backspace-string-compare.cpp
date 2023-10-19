class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 19.10.23 POTD

        string a, b;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='#'){
                if(a.size())
                    a.pop_back();
            }   
            else    a += s[i];
        }

        for(int i=0; i<t.size(); i++){
            if(t[i]=='#'){
                if(b.size())
                    b.pop_back();
            }
            else    b += t[i];
        }

        return a==b;
    }
};