class Solution {
public:
    int maxGold = 0;
    vector<int> row = {-1,1,0,0};
    vector<int> col = {0,0,-1,1};

    int getMaximumGold(vector<vector<int>>& grid) {
        // 14.05.24 potd
        int n=grid.size(), m=grid[0].size();

        int count = checkIfAllNonZeros(grid);
        if(count){
            return count;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0)
                    backtrack(grid, i, j, 0);
            }
        }

        return maxGold;
    }

    int checkIfAllNonZeros(vector<vector<int>> &grid){
        int count = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    return 0;
                }

                count += grid[i][j];
            }
        }

        return count;
    }

    void backtrack(vector<vector<int>> &grid, int x, int y, int count){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==0)
            return;

        int gold = grid[x][y];
        grid[x][y] = 0;
        count += gold;

        maxGold = max(maxGold, count);

        for(int i=0; i<4; i++){
            int nx = x + row[i];
            int ny = y + col[i];
            backtrack(grid, nx, ny, count);
        }

        grid[x][y] = gold;
    }
};