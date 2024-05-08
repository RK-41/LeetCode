class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // 08.05.24 POTd
        
        vector<string> ans;
        vector<int> v(score.begin(), score.end());
        unordered_map<int,int> sortedIdx;

        sort(v.begin(), v.end(), greater<int>());
        
        for(int i=0; i<v.size(); i++){
            sortedIdx[v[i]] = i;
        }

        for(int i=0; i<score.size(); i++){
            int idx = sortedIdx[score[i]];
            
            if(idx > 2){
                ans.push_back(to_string(idx+1));
            } else if(idx == 0){
                ans.push_back("Gold Medal");
            } else if(idx == 1){
                ans.push_back("Silver Medal");
            } else {
                ans.push_back("Bronze Medal");
            }
        }

        return ans;
    }
};