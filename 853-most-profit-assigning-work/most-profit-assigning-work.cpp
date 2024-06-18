class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // 18.06.24 potd
        int totalProfit = 0;
        int maxDiff = *max_element(difficulty.begin(), difficulty.end());
        vector<int> maxProfitUpToDifficulty(maxDiff + 1, 0);

        for(int i=0; i<difficulty.size(); i++){
            maxProfitUpToDifficulty[difficulty[i]] = max(maxProfitUpToDifficulty[difficulty[i]], profit[i]);
        }

        for(int i=1; i<=maxDiff; i++){
            maxProfitUpToDifficulty[i] = max(maxProfitUpToDifficulty[i], maxProfitUpToDifficulty[i-1]);
        }

        for(int ability: worker){
            if(ability > maxDiff){
                totalProfit += maxProfitUpToDifficulty[maxDiff];
            } else {
                totalProfit += maxProfitUpToDifficulty[ability];
            }
        }

        return totalProfit;
    }
};