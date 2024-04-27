#include<climits>
#include<algorithm>

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // 27.04.24 potd
        unordered_map<char, vector<int>> positions;
        vector<vector<int>> memo(key.size(), vector<int>(ring.size(),-1));
        for(int i=0; i<ring.size(); i++){
            positions[ring[i]].push_back(i);
        }

        return helper(0,0,positions,key,ring,memo);
    }

    int helper(int idx, int pos, unordered_map<char, vector<int>>& positions, string& key, string& ring, vector<vector<int>> &memo){
        if(idx == key.size()){
            return 0;
        }
        if(memo[idx][pos] != -1){
            return memo[idx][pos];
        }

        int minSteps = INT_MAX;
        for(int i: positions[key[idx]]){
            int steps;
            if(i>=pos){
                steps = min(i-pos, static_cast<int>(pos + ring.size()) - i);
            } else {
                steps = min(pos-i, static_cast<int>(i + ring.size()) - pos);
            }

            int nextSteps = helper(idx+1,i,positions,key,ring,memo);
            minSteps = min(minSteps, steps + nextSteps);
        }

        memo[idx][pos] = minSteps + 1;
        return minSteps+1;
    }
};