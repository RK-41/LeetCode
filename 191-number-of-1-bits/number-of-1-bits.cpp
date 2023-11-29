class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 29.11.23 POTD

        return __builtin_popcount(n);
    }
};