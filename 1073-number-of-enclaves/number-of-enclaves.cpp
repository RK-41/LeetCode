class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // 29.09.23
        // Approach: Floodfill Algorithm

        int n=grid.size(), m=grid[0].size();

        // Converting all the 1's on the boundaries along with their four-directionally
        //  adjacent 1's to 2's
        for(int i=0; i<n; i++)
            if(grid[i][0]==1)   dfs(grid, i, 0, n, m);

        for(int j=0; j<m; j++)
            if(grid[0][j]==1)   dfs(grid, 0, j, n, m);

        for(int i=0; i<n; i++)
            if(grid[i][m-1]==1) dfs(grid, i, m-1, n, m);

        for(int j=0; j<m; j++)
            if(grid[n-1][j]==1) dfs(grid, n-1, j, n, m);

        // Now, only those 1's remain in the grid which can't be walked off
        int count = 0;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==1)   count++;

        return count;
    }

    void dfs(vector<vector<int>>&grid, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;

        grid[i][j] = 2;

        dfs(grid, i-1, j, n, m);
        dfs(grid, i, j-1, n, m);
        dfs(grid, i+1, j, n, m);
        dfs(grid, i, j+1, n, m);
    }
};