#define vi vector<int>
#define vvi vector<vi>

class Solution {
// 31.01.25 potd
    // Dir vectors
    int d[5] = {1, 0, -1, 0, 1};
    int n;

    // DFS to mark island and calculate its size
    int dfs(int r, int c, int id, vvi &grid){
        // mark cell with island id
        grid[r][c] = id;

        // initialize size of the island
        int cnt = 1;

        // explore all 4 dir
        for(int i=0; i<4; i++){
            int nr = r + d[i], nc = c + d[i+1];

            if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1){
                cnt += dfs(nr, nc, id, grid);
            }
        }

        return cnt;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vi key; // stores sizes of all islands
        int id = 2; // island id starting from 2

        // identify all islands and calc their sizes
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    key.push_back(dfs(i, j, id++, grid));
            }
        }

        // grid containing no land
        if(key.empty()) return 1;

        int ans = 1;

        // checking all water cells and calculating potential island size
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    int cnt = 1;

                    // adding sizes of neighboring islands
                    for(int k=0; k<4; k++){
                        int nr = i + d[k], nc = j + d[k+1];

                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] != 0 && key[grid[nr][nc] - 2] > 0)
                            // mark island as visited
                            cnt += key[grid[nr][nc] - 2], key[grid[nr][nc] - 2] *= -1;
                    }

                    // resetting sizes of marked islands
                    for(int k=0; k<4; k++){
                        int nr = i + d[k], nc = j + d[k+1];

                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] != 0 && key[grid[nr][nc] - 2] < 0)
                        // unmark island
                        key[grid[nr][nc] - 2] *= -1;
                    }
                
                    // updating the largest possible island size
                    ans = max(ans, cnt);
                }
            }
        }

        return ans == 1 ? n*n : ans;
    }
};