class Solution {
public:
    int minBitFlips(int start, int goal) {
        // 11.09.24 POTD
        return __builtin_popcount(start ^ goal);
    }
};