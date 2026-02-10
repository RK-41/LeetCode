constexpr int N=1e5+1;
short fr[N] = {0};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // 10.02.26 potd
        int ans = 0;
        const int n = nums.size();

        for(int i=0; i<n; i++){
            int cnt[2] = {0};
            for(int j=i; j<n; j++){
                const int x = nums[j];
                if(++fr[x] == 1)    cnt[x&1]++;
                if(cnt[0] == cnt[1])    ans = max(ans, j-i+1);
            }

            for(int k=i; k<n; k++)  fr[nums[k]] = 0;
        }

        return ans;
    }
};