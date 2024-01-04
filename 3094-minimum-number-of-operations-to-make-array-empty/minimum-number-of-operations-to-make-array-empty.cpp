class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 05.01.24 potd
        unordered_map<int,int> um;
        for(auto a: nums){
            um[a]++;
        }

        int count=0;
        for(auto p: um){
            int t = p.second;
            if(t==1)    return -1;
            count += t/3;
            if(t%3) count++;
        }

        return count;
    }
};