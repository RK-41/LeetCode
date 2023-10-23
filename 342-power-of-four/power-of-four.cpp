class Solution {
public:
    bool isPowerOfFour(int n) {
        // 23.10.23 POTD

        if(n==1 or n==4)    return true;
        if(n<4 or n%4!=0) return false;

        while(n>4){
            n /= 4;

            if(n%4 != 0) return false;
        }
        
        return true;
    }
};