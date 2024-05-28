class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // 28.05.24 potd
        int ans=0, cost=0, start=0, n=s.size();
        
        for(int end=0; end<n; end++){
            cost += abs(s[end]-t[end]);

            while(cost > maxCost){
                cost -= abs(s[start] - t[start]);
                ++start;
            }

            ans = max(ans, end-start+1);
        }

        return ans;
    }
};