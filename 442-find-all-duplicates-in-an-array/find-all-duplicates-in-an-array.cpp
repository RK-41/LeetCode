class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // 24.09.23 
        // AND IT WORKS!
        // 25.03.24 (POTD)
        
        vector<int> ans;

        for(auto &n: nums){
            if(nums[abs(n)-1] < 0){
                ans.push_back(abs(n));
            }
            nums[abs(n)-1] *= -1;
        }

        return ans;
    }
};