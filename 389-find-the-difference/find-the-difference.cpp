class Solution {
public:
    char findTheDifference(string s, string t) {
        // 25.09.23 POTD

        return accumulate(t.begin(), t.end(), 0) - accumulate(s.begin(), s.end(), 0);

        // int d=0;
        // for(int i=0; i<s.size(); i++){
        //     d -= s[i],  d += t[i];
        // }
        // return d==0? t.back() : d+t.back();
    }
};
