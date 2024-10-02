class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // 02.10.24 POTD
        if(arr.empty()) return {};
        
        vector<int> ans, brr=arr;
        unordered_map<int,int> ranking;
        sort(brr.begin(), brr.end());
        int rank=1, prev=brr[0];

        for(auto b: brr){
            if(b > prev){
                rank++;
                prev = b;
            }
            ranking[b] = rank;
        }

        for(auto a: arr){
            ans.push_back(ranking[a]);
        }

        return ans;
    }
};