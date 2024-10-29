class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // 29.10.24 POTD
        int ans=0, m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            calculate(grid, dp, ans, 0, i, 0, m, n);
            ans = max(ans, dp[i][0]); 
        }

        return ans;
    }

    int calculate(vector<vector<int>>& grid, vector<vector<int>>& dp, int& ans, int prev, int r, int c, int m, int n){
        if(r<0 || r>=m || c>=n || prev >= grid[r][c])    return 0;
        if(dp[r][c] != -1)  return dp[r][c];

        int u = calculate(grid, dp, ans, grid[r][c], r-1, c+1, m, n);
        int f = calculate(grid, dp, ans, grid[r][c], r, c+1, m, n);
        int d = calculate(grid, dp, ans, grid[r][c], r+1, c+1, m, n);

        dp[r][c] = max({u,f,d});
        ans = max(ans, dp[r][c]);
        return dp[r][c] + 1;
    }
};