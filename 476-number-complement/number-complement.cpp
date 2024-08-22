class Solution {
public:
    int findComplement(int num) {
        // 22.08.24 POTD
        int ans=0, exp=0;

        while(num>0){
            int d = num%2;
            if(d == 0)
                ans += pow(2,exp);

            exp++;
            num /= 2;
        }

        return ans;
    }
};