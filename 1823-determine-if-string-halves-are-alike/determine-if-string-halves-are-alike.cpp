class Solution {
public:
    bool halvesAreAlike(string s) {
        // 12.01.24 POTD
        int vc=0, n=s.size();

        for(int i=0; i<n/2; i++){
            if(isV(s[i]))
                vc++;
        }

        for(int i=n/2; i<n; i++){
            if(isV(s[i]))
                vc--;
        }

        return vc==0;
    }

    bool isV(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
};