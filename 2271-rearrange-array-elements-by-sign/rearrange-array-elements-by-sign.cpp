class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // 14.02.24 POTD
        int n=nums.size();
        vector<int> ans, pos, neg;

        for(int i=0; i<n; i++){
            if(nums[i]<0)
                neg.push_back(i);
            else 
                pos.push_back(i);
        }

        for(int i=0; i<n/2; i++){
            ans.push_back(nums[pos[i]]);
            ans.push_back(nums[neg[i]]);
        }

        return ans;
    }
};