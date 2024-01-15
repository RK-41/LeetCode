class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // 15.01.24 POTD
        vector<vector<int>> ans;
        unordered_map<int,int> lostCount;
        vector<int> winner, loser;

        for(auto r: matches){
            lostCount[r[1]]++;
        }

        for(auto r: matches){
            if(lostCount.find(r[0]) == lostCount.end()){
                winner.push_back(r[0]);
                lostCount[r[0]]--;
            }
        }

        for(auto p: lostCount){
            if(p.second == 1){
                loser.push_back(p.first);
            }
        }

        sort(winner.begin(), winner.end());
        sort(loser.begin(), loser.end());

        return vector{winner, loser};
    }
};