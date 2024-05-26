class Solution {
public:
    int checkRecord(int n) {
        // 26.05.24 potd
        const int MOD = 1000000007;
        vector<vector<int>> dp_last(2, vector<int>(3,0)); // prev state
        vector<vector<int>> dp_curr(2, vector<int>(3,0)); // curr state

        dp_last[0][0] = 1; // empty string

        for(int i=0; i<n; i++){
            for(int countA=0; countA<2; countA++){
                for(int countL=0; countL<3; countL++){
                    // Choosing 'P'
                    dp_curr[countA][0] = (dp_curr[countA][0] + dp_last[countA][countL])%MOD;

                    // Choosing 'A'
                    if(countA==0){
                        dp_curr[countA+1][0] = (dp_curr[countA+1][0] + dp_last[countA][countL])%MOD;
                    }

                    // Choosing 'L'
                    if(countL < 2){
                        dp_curr[countA][countL+1] = (dp_curr[countA][countL+1] + dp_last[countA][countL])%MOD;
                    }
                }
            }

            dp_last = dp_curr;
            dp_curr = vector<vector<int>>(2, vector<int>(3,0));
        }

        // Summin up the counts for all combinations of lenght 'n' with diff countA and countL
        int ans=0;
        for(int cA=0; cA<2; cA++){
            for(int cL=0; cL<3; cL++){
                ans = (ans + dp_last[cA][cL])%MOD;
            }
        }

        return ans;
    }
};