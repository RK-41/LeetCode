class Solution {
public:
    int pivotInteger(int n) {
        // 13.03.24 POTD
        // if(n==1)
        //     return 1;

        int x=1, sum=0, total = n*(n+1)/2;
        while(x<=n){
            if(sum == (total-sum-x))
                return x;

            sum += x;
            x++;
        }

        return -1;
    }
};