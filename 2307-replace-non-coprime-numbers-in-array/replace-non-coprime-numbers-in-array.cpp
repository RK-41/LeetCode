static int st[100000], top=-1;
class Solution {
public:
    // 16.09.25 potd
    static int lcm(int x, int y) {
        return x/gcd(x, y)*y;
    }

    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        top=-1;// reset st
        for (int x : nums) {
            int cur=x;
            while (top!=-1) {
                int g=gcd(st[top], cur);
                if (g==1) break;
                cur=lcm(st[top], cur);
                top--;// pop 
            }
            st[++top]=cur;
        }

        return vector<int>(st, st+top+1);
    }
};