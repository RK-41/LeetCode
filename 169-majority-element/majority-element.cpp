class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 12.02.24 POTD
        unordered_map<int,int> fr;
        for(auto n: nums){
            fr[n]++;
            if(fr[n]>(nums.size()/2))
                return n;
        }

        return -1;
    }
};