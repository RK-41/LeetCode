class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // 16.12.23 POTD(15.12.23)

        set<string> start;
        string ans;
        for(auto p: paths){
            start.insert(p[0]);
        }

        for(auto p: paths){
            if(start.find(p[1]) == start.end()){
                ans = p[1];
                break;
            }
        }

        return ans;
    }
};