class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // 26.04.24 potd
        int n=grid.size(), ans=INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,-1));

        for(int j=0; j<n; j++){
            dp[0][j] = grid[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int temp = INT_MAX;

                for(int k=0; k<n; k++){
                    if(k != j){
                        temp = min(temp, grid[i][j] + dp[i-1][k]);
                    }

                    dp[i][j] = temp;
                }
            }
        }

        for(int j=0; j<n; j++){
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};