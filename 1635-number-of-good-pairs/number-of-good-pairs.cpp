class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // 03.10.23 POTD

        int ans=0;
        unordered_map<int,int> fr;
        fr[nums[0]]=1;

        for(int i=1; i<nums.size(); i++){
            ans += fr[nums[i]];

            fr[nums[i]]++;
        }

        return ans;
    }
};