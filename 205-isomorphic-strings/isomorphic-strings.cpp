class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 02.04.24 (POTD)
        if(s.length()!=t.length())
            return 0;

        unordered_map<char,char> um1, um2;

        for(int i=0; i<s.length(); i++){
            
            if(um1.find(s[i])!=um1.end() && um1[s[i]]!=t[i])
                    return 0;
            else
                um1[s[i]]=t[i];


            if(um2.find(t[i])!=um2.end() && um2[t[i]]!=s[i])
                return 0;
            else
                um2[t[i]]=s[i];
        }

        return 1;
    }
};