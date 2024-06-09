class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // 09.06.24 potd
        int count=0, cumSum=0;
        unordered_map<int,int> cumMap;

        // To handle subarray that start from index 0
        cumMap[0] = 1;

        for(int n: nums){
            cumSum += n;

            int mod = cumSum%k;

            if(mod < 0){
                mod += k;
            }

            count += cumMap[mod];
            cumMap[mod] += 1;
        }

        return count;
    }
};