class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        // 12.11.24 POTd
        vector<int> ans;
        unordered_map<int, int> maxB;
        vector<int> uniqueP;
        int mx = 0;
        sort(items.begin(), items.end());

        for (auto i : items) {
            mx = max(mx, i[1]);
            maxB[i[0]] = max(maxB[i[0]], mx);
            if(uniqueP.empty() || uniqueP.back() != i[0]){
                uniqueP.push_back(i[0]);
            }
        }

        for (auto q : queries) {
            auto p = lower_bound(uniqueP.begin(), uniqueP.end(), q);
            int pr = p == uniqueP.begin() ? (q < *p ? 0 : *p) : (p == uniqueP.end() ? *(--p) : (q < *p ? *(--p) : *p));
            ans.push_back(maxB[pr]);
        }

        return ans;
    }
};