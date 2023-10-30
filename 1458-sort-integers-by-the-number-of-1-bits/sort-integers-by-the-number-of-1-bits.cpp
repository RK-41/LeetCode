class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // 30.10.23 potd

        // APPROACH 1:
        // vector<int> ans;
        // unordered_map<int, vector<int>> um;
        // int mx = INT_MIN;

        // for(auto a: arr){
        //     um[__builtin_popcount(a)].push_back(a);
        //     mx = max(mx, a);
        // }

        // for(int i=0; i<=log2(mx); i++){
        //     sort(um[i].begin(), um[i].end());
        //     ans.insert(ans.end(), um[i].begin(), um[i].end());
        // }

        // return ans;


        // Approach 2:
        int n = arr.size();
        vector<int> res(n);

        for(int i=0; i<n; i++)
            res[i] = __builtin_popcount(arr[i])*10001 + arr[i];

        sort(res.begin(), res.end());

        for(int i=0; i<n; i++){
            res[i] %= 10001;
        }

        return res;
    }
};