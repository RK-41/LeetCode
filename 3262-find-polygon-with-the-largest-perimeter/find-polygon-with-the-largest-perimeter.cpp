class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // 15.02.24 Potd
        long long ans=0;
        sort(nums.begin(), nums.end());
        
        for(auto n: nums)
            ans += n;

        int i=nums.size()-1;

        while(i>=2){
            ans -= nums[i];

            if(ans > nums[i])
                return ans + nums[i];

            i--;
        }

        return -1;
    }
};