class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // 07.07.24 POTD
        int ans = numBottles, nb = numBottles;

        while(numBottles >= numExchange){
            ans += numBottles/numExchange;
            nb %= numExchange;
            nb += numBottles/numExchange;

            numBottles = nb;
        }

        return ans;
    }
};