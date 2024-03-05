class Solution {
public:
    int minimumLength(string s) {
        // 05.03.24 POTD
        int n=s.size();
        if(n==1)    return 1;
        if(s[0]!=s[n-1])    return n;

        int i=0, j=n-1;
        while(i<j){
            if(s[i]!=s[j])
                break;

            char c=s[i];
            while(s[i]==c && i<=j)
                i++;
            while(s[j]==c && j>i)
                j--;
        }

        if(i==j && s[i-1]==s[j+1])
            return !(s[i-1]==s[i]);

        return j<i ? 0 : j-i+1;
    }
};