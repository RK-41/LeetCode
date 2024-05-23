class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // 23.05.24 potd
        unordered_map<int,int> um;
        int ans = dfs(nums, 0, k, um)-1;

        return ans;
    }

    int dfs(vector<int>& nums, int idx, int k, unordered_map<int,int>& um){
        if(idx == nums.size())  return 1;

        int taken = 0;
        if(!um[nums[idx] - k] && !um[nums[idx] + k]){
            um[nums[idx]]++;
            taken = dfs(nums, idx+1, k, um);
            um[nums[idx]]--;
        }

        int notTaken = dfs(nums, idx+1, k, um);

        return taken + notTaken;
    }
};