class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 05.10.23 POTD

        unordered_map<int,int> fr;
        vector<int> ans;

        for(auto n: nums){
            fr[n]++;
            if(fr[n] > floor(nums.size()/3)){
                ans.push_back(n);
                fr[n] -= nums.size();
            }
        }

        return ans;
    }
};