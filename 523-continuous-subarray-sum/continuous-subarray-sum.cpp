class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 08.06.24 potd
        int n = nums.size();
        if(n == 1)  return false;
        if(n == 2){
            if((nums[0]+nums[1])%k == 0)
                return true;
            return false;
        }

        unordered_map<int,int> remainderIdx;    // {rem, idx}
        long long cumSum = 0;

        remainderIdx[0] = -1;

        for(int i=0; i<n; i++){
            cumSum += nums[i];

            int remainder = k == 0 ? cumSum : cumSum%k;

            if(remainderIdx.count(remainder)){
                if(i - remainderIdx[remainder] > 1)
                    return true;
            } else {
                remainderIdx[remainder] = i;
            }
        }

        return false;
    }
};