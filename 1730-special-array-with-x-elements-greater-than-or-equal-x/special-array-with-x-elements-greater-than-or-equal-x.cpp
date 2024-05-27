class Solution {
public:
    int specialArray(vector<int>& nums) {
        // 27.05.24 POTD
        int n = nums.size();
        int mn = *min_element(nums.begin(), nums.end());

        if(n <= mn)
            return n;

        int mx = *max_element(nums.begin(), nums.end());
        if(mx == 0)
            return -1;
        
        unordered_map<int,int> um;
        for(int i=1; i<=n; i++){
            if(um[i] > 0)   continue;
            
            for(auto e: nums){
                if(i <= e){
                    um[i]++;
                }
            }

            if(i == um[i])
                return i;
        }

        return -1;
    }
};