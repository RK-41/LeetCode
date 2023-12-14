class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // 14.12.23 POTD

        vector<vector<int>> diff;
        int m=grid.size(), n=grid[0].size();
        vector<int> onesRow(m,0), onesCol(n,0);

        for(int i=0; i<m; i++){
            onesRow[i] = accumulate(grid[i].begin(), grid[i].end(), 0);
        }

        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                onesCol[j] += grid[i][j];
            }
        }

        for(int i=0; i<m; i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                v.push_back(2*onesRow[i]+2*onesCol[j]-n-m);
            }
            diff.push_back(v);
        }

        return diff;
    }
};