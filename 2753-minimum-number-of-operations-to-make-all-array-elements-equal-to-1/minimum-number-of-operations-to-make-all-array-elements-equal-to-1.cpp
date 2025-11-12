class Solution {
public:
    // 12.11.25 potd
    static int GCD(unsigned x, unsigned y){
        int bz=min(countr_zero(x), countr_zero(y));
        if (bz>1) return GCD(x>>bz, y>>bz)<<bz;
        for(unsigned r; y; x=y, y=r) r=x%y;
        return x;
    }
    static int minOperations(vector<int>& nums) {
        const int n=nums.size(), cnt1=count(nums.begin(), nums.end(), 1);
        if (cnt1>0) return n-cnt1;
        for(int d=2; d<=n; d++){
            for(int l=0; l<=n-d; l++){
                int g=nums[l]=GCD(nums[l], nums[l+1]);
                if (g==1) return d+n-2;
            }
        }
        return -1;
    }
};