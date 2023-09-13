class Solution {
public:
    int candy(vector<int>& ratings) {
        // 13.09.23 Potd

        int ans = 0, n = ratings.size();

        vector<int> candies(n, 1);
        int i=1, j=n-2;

        while(i<n){
          if(ratings[i] > ratings[i-1])
            candies[i] = candies[i-1]+1;

          i++;
        }

        while(j>=0){
          if(ratings[j] > ratings[j+1])
            candies[j] = max(candies[j], candies[j+1]+1);

          j--;
        }
    
        for(auto c: candies)
          ans += c;

        return ans;
    }
};