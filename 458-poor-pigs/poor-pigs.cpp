class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // 29.10.23 potd

        return ceil(log2(buckets)/log2(int(minutesToTest/minutesToDie)+1));
    }
};