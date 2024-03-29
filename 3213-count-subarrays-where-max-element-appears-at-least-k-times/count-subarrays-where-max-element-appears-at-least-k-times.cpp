class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // 29.03.24 potd
        long long ans=0, l, r;
        vector<int> maxIndex(1, -1);
        int n=nums.size();

        int mx = *max_element(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] == mx){
                maxIndex.push_back(i);
            }
        }

        int idxSz = maxIndex.size();

        for(int i=1; i<=idxSz-k; i++){
            // Calculate 'l' as the difference between the current index and
            //  previous max index
            l = maxIndex[i] - maxIndex[i-1] - 1;

            // Calculate 'r' (no. of elements to the right of the window)
            r = n - 1 - maxIndex[i+k-1];

            ans += (l+1)*(r+1);
        }

        return ans;
        
    }
};