class Solution {
public:
    int findKthNumber(int n, int k) {
        // 22.09.24 potd
        long ans=1;

        for(int i=1; i<k;){
            int req = getReqNum(ans, ans+1, n);
            if(i+req <= k){
                i += req;
                ans++;
            } else {
                i++;
                ans *= 10;
            }
        }

        return ans;
    }

private:
    int getReqNum(long a, long b, long n){
        int gap = 0;
        while(a <= n){
            gap += min(n+1, b) - a;
            a *= 10;
            b *= 10;
        }

        return gap;
    }
};