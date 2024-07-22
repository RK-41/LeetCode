class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // 22.07.24 POTD
        vector<string> ans;
        unordered_map<int,string> heightPeople;

        for(int i=0; i<names.size(); i++){
            heightPeople[heights[i]] = names[i];
        }

        sort(heights.rbegin(), heights.rend());

        for(auto h: heights){
            ans.push_back(heightPeople[h]);
        }

        return ans;
    }
};