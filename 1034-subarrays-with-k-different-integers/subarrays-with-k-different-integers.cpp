#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // 30.03.24 potd
        int n=nums.size();

        return (k==1) ? goodLessEqualK(nums, 1, n) : goodLessEqualK(nums, k, n) - goodLessEqualK(nums, k-1, n);
    }

    int goodLessEqualK(vector<int> &nums, int k, int &n){
        int cnt=0, distinct=0, freq[20001]={0};

        for(int l=0, r=0; r<n; r++){
            int x = nums[r];
            distinct += (++freq[x]==1);

            while(distinct > k){
                int y = nums[l];
                distinct -= (--freq[y]==0);
                l++;
            }

            cnt += (r-l+1);
        }

        return cnt;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
};