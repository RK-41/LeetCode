class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 15.03.24 POTD
        int n=nums.size();
        vector<int> pre(n,1), post(n,1), ans(n);

        pre[1] = nums[0];
        post[n-2] = nums[n-1];
        for(int i=1; i<n; i++){     
            pre[i] = nums[i-1]*pre[i-1];
            post[n-1-i] = nums[n-i]*post[n-i];
        }

        ans[0] = post[0];
        ans[n-1] = pre[n-1];
        for(int i=1; i<n-1; i++){
            ans[i] = pre[i]*post[i];
        }

        return ans;
    }
};