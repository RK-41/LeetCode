class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 19.02.24 (POTD)
        int pc = __builtin_popcount(n);

        return pc>1 ? false : n>0 ? true : false;
    }
};