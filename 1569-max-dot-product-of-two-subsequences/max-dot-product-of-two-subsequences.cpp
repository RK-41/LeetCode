class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // 08.10.23 potd
        // Approach: DP

        int m = nums1.size(), n = nums2.size();
        vector<int> curr(n+1, INT_MIN), prev(n+1, INT_MIN);

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                int curr_prod = nums1[i-1] * nums2[j-1];

                curr[j] = max({curr_prod, prev[j], curr[j-1], curr_prod+max(0, prev[j-1])});
            }

            swap(curr, prev);
        }

        return prev[n];

    }
};