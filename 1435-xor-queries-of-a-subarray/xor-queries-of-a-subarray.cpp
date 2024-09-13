class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // 13.09.24 potd
        int n = arr.size();
        vector<int> ans(queries.size()), pre(n);
        pre[0] = arr[0];

        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] ^ arr[i];
        }

        for(int k=0; k<queries.size(); k++){
            int i = queries[k][0], j = queries[k][1];
            if(i==0)    ans[k] = pre[j];
            else    ans[k] = pre[j] ^ pre[i-1];
        }

        return ans;
    }
};