class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // 07.07.24 POTD
        int ans = numBottles;

        while(numBottles >= numExchange){
            numBottles += 1 - numExchange;
            ans++;
        }

        return ans;
    }
};