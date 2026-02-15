class Solution {
public:
    string addBinary(string a, string b) {
        // 15.02.26 POTD
        if(a == "0")    return b;
        if(b == "0")    return a;
        string ans = "";
        int n = a.size(), m = b.size(), c = 0;

        for(int i=0; i<max(n,m); i++){
            if(i<n){
                c += (a[n-1-i] - '0');
            }
            if(i<m){
                c += (b[m-1-i] - '0');
            }

            if(c%2==0) ans += "0";
            else    ans += "1";
            c = max(min(1, c-1), 0);
        }

        while(c>0){
            if(c>1) ans += "0";
            else    ans += "1";
            c--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};