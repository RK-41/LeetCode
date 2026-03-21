class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // 21.03.26 POTD
        for(int i=0; i<k/2; i++){
            for(int j=y; j<y+k; j++){
                int d = grid[i+x][j];
                grid[i+x][j] = grid[x+k-i-1][j];
                grid[x+k-i-1][j] = d;
            }
        }

        return grid;
    }
};