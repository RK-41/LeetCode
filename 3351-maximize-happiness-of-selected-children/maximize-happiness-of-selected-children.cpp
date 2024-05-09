class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // 09.05.24 POTD
        long long ans=0;
        int t=0;
        sort(happiness.begin(), happiness.end());
        
        for(int i=happiness.size()-1; i>=0, k>0; i--, k--){
            if(happiness[i]-t > 0){
                ans += happiness[i]-t;
            } else {
                break;
            }
            t++;
        }

        return ans;
    }
};