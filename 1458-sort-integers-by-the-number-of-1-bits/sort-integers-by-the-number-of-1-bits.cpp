class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // 30.10.23 POTD


        vector<int> ans;
        unordered_map<int, vector<int>> um;
        int mx = INT_MIN;

        for(auto a: arr){
            um[__builtin_popcount(a)].push_back(a);
            mx = max(mx, a);
        }

        for(int i=0; i<=log2(mx); i++){
            sort(um[i].begin(), um[i].end());
            ans.insert(ans.end(), um[i].begin(), um[i].end());
        }

        return ans;
    }
};
        // sort(arr.begin(), arr.end(), [](int a, int b){
        //    return __builtin_popcount(a) < __builtin_popcount(b);
        // });