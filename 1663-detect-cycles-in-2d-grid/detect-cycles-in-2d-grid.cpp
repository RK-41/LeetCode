class Solution {
    static constexpr int dirs[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
public:
    bool containsCycle(vector<vector<char>>& grid) {
        // 26.04.26 potd
        int m = grid.size(), n = grid[0].size();
        bitset<250005> vis;

        auto dfs = [&](this auto&& dfs, int r, int c, int pr, int pc) -> bool {
            vis[r*n + c] = 1;

            for(const auto& d: dirs){
                int nr = r+d[0];
                int nc = c+d[1];

                if(nr != pr || nc != pc){
                    // Check if in bounds
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        if(grid[nr][nc] == grid[r][c])  // same char -> follow path
                            if(vis[nr*n + nc] || dfs(nr, nc, r, c))
                                return true;
                    }
                }
            }

            return false;
        };

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i*n + j] && dfs(i, j, -1, -1))
                    return true;
            }
        }

        return false;
    }
};