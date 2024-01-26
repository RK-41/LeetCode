class Solution {
public:
    int M=1e9+7;
    vector<vector<vector<int>>> dp;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // 26.01.24 potd
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return solve(n, m, maxMove, startRow, startColumn);
    }

    int solve(int n, int m, int mx, int r, int c){
        if(c<0 || c>=n || r<0 || r>=m)  return 1;
        if(mx==0)   return 0;

        if(dp[r][c][mx] != -1)  return dp[r][c][mx];

        int up=0, down=0, left=0, right=0;

        if(mx>0) up=solve(n, m, mx-1, r-1, c);
        if(mx>0) down=solve(n, m, mx-1, r+1, c);
        if(mx>0) left=solve(n, m, mx-1, r, c-1);
        if(mx>0) right=solve(n, m, mx-1, r, c+1);

        return dp[r][c][mx] = ((up+down)%M + (left+right)%M)%M;
    }
};