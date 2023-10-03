class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // 03.10.23 POTD

        int ans=0;
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++)
        //         if(nums[i] == nums[j])
        //             ans++;
        // }

        // return ans;

        unordered_map<int,int> fr;
        fr[nums[0]]=1;

        for(int i=1; i<nums.size(); i++){
            ans += fr[nums[i]];

            fr[nums[i]]++;
        }

        return ans;
    }
};