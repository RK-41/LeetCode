class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        // 27.10.24 potd
        int ans=0, n=mat.size(), m=mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            dp[i][0] = mat[i][0];
            ans += dp[i][0];
        }

        for(int j=1; j<m; j++){
            dp[0][j] = mat[0][j];
            ans += dp[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][j]){
                    // For each cell, check the min val among:
                    // left cell, top cell, top-left diagonal cell
                    // Add 1 to this min val
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }

                ans += dp[i][j];
            }
        }

        return ans;
    }
};