class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // 24.11.23 POTD
        sort(piles.begin(), piles.end());
        int ans = 0, l=0, r=piles.size()-2;

        while(l<r){
            ans += piles[r];
            l++;
            r-=2;
        }

        return ans;
    }
};