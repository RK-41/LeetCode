class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // 23.07.24 POTD
        vector<int> ans;
        unordered_map<int,int> fr;
        unordered_map<int,vector<int>> commonFr;

        for(auto n: nums){
            fr[n]++;
        }

        int mxFr=1;

        for(auto p: fr){
            commonFr[p.second].push_back(p.first);
            mxFr = max(mxFr, p.second);
        }

        for(int i=1; i<=mxFr; i++){
            vector<int> v = commonFr[i];
            if(v.size()>1){
                sort(v.rbegin(), v.rend());
            }

            for(auto n: v){
                for(int j=0; j<i; j++)
                    ans.push_back(n);
            }
        }

        return ans;
    }
};