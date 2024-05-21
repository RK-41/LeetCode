class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 21.05.24 POTD
        vector<vector<int>> subsets = {{}};
        queue<vector<int>> q;
        int n = nums.size();

        for(int a: nums){
            subsets.push_back({a});
        }        

        int i=0;
        while(i<n){
            int sz = q.size();

            while(sz--){
                auto f = q.front();
                q.pop();
                q.push(f);

                f.push_back(nums[i]);
                q.push(f);

                subsets.push_back(f);
            }
            q.push({nums[i]});
            i++;
        }
        
        return subsets;
    }
};