class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // 02.01.26 POTD
        unordered_map<int,int> um;
        int n = nums.size()/2;

        for(auto a: nums){
            um[a]++;
            if(um[a] == n)
                return a;
        }

        return 0;
    }
};