class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // 02.05.24 POTD
        int ans=-1;

        unordered_map<int,int> um;
        for(auto n: nums){
            um[n] = n>0 ? 1 : -1;

            if(n<0 && um[abs(n)]==1){
                ans = max(ans,abs(n));
            } else if(um[-n]==-1){
                ans = max(ans, n);
            }
        }

        return ans;
    }
};