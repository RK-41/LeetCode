class Solution {
public:
    int appendCharacters(string s, string t) {
        // 03.06.24 POTD
        int ans=0, i=0, j=0, n=s.size(), m=t.size();

        while(i<n && j<m){
            if(s[i] == t[j]){
                j++;
            }

            i++;
        }

        return m-j;
    }
};