class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 31.05.24 POTd
        if(nums.size() == 2)
            return nums;

        long long int xr1=0, xr2=0;
        for(int a: nums){
            xr1 ^= a;
        }

        int lowestSetBit = xr1 & (-xr1);
        xr1 = 0;
        for(int a: nums){
            if(lowestSetBit & a){
                xr1 ^= a;
            } else {
                xr2 ^= a;
            }
        }

        return {int(xr1), int(xr2)};
    }
};