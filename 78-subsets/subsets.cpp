class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 01.06.24
        vector<vector<int>> subsets;
        int n = nums.size();
        int total = 1<<n;

        for(int i=0; i<total; i++){
            vector<int> sub;
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    sub.push_back(nums[j]);
                }
            }

            subsets.push_back(sub);
        }

        return subsets;
    }
};