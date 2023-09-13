class Solution {
public:
    int candy(vector<int>& ratings) {
        // 13.09.23 Potd
        // Approach: Greedy - Two pass
        
        int ans = 0, n = ratings.size();
        vector<int> candies(n, 1);
        int i=1, j=n-2;

        // iterating from left to right to allot candies to children
        // having higher rating than their left neighbour
        while(i<n){
          if(ratings[i] > ratings[i-1])
            candies[i] = candies[i-1]+1;

          i++;
        }

        // iterating from right to left to allot candies (if needed) to children
        // having higher rating than their right neighbour
        while(j>=0){
          if(ratings[j] > ratings[j+1])
            candies[j] = max(candies[j], candies[j+1]+1);

          j--;
        }

        // summing up the candies count
        for(auto c: candies)
          ans += c;

        return ans;
    }
};