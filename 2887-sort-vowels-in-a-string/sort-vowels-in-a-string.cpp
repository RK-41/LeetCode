class Solution {
public:
    string sortVowels(string s) {
        // 13.11.23 POTD

        string t;
        vector<char> upr, lwr;

        for(auto ch: s){
            if(isVowel(ch)){
                if(ch>=65 && ch<=90)
                    upr.push_back(ch);
                else if(ch>=97 && ch<=122)
                    lwr.push_back(ch);
            }
        }

        sort(upr.begin(), upr.end());
        sort(lwr.begin(), lwr.end());

        int u=0, l=0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                if(u<upr.size())
                    t += upr[u++];
                else
                    t += lwr[l++];
            } else {
                t += s[i];
            }
        }

        return t;
    }

    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
};