class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 06.02.24 potd
        unordered_map<string, vector<string>> group;

        for(const string& w: strs){
            // Sort the chars in the word to create a key
            string key=w;
            sort(key.begin(), key.end());

            // If key is not in the map, add a new entry with the word a vector
            if(group.find(key) == group.end()){
                group[key]={w};
            } else {
                group[key].push_back(w);
            }
        }

        // Converting map values to a vector;
        vector<vector<string>> ans;
        for(const auto& g: group){
            ans.push_back(g.second);
        }

        return ans;
    }
};