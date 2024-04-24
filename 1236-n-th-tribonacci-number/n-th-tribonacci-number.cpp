class Solution {
public:
    int tribonacci(int n) {
        // 24.04.24 POTD
        if(n==0)    return 0;
        if(n==1 || n==2)    return 1;

        int t0=0, t1=1, t2=1, ans=2;
        while(n-->2){
            ans = t2 + t1 + t0;
            t0 = t1;
            t1 = t2;
            t2 = ans;
        }

        return ans;
    }
};