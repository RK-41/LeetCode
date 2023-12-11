class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // 11.12.23 POTD

        unordered_map<int,int> um;
        int ans;
        for(auto a: arr){
            um[a]++;
            
            if(um[a] > arr.size()/4){
                ans=a;
                break;
            }
        }

        return ans;
    }
};