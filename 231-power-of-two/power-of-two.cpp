class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 19.02.24 POTD
        if(n == 1)    return true;
        if(n == 0 || n%2 == 1)    return false;

        int pc = __builtin_popcount(n);
        return pc>1 ? false : n>0 ? true : false;
    }
};