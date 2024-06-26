#pragma GCC optimize ("0fast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("03", "unroll-loops")

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
       // 13.05.24 potd
       ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
       int n=grid.size(), m=grid[0].size();
       int ans = (1<<(m-1))*n;

       for(int j=1; j<m; j++){
        int val = 1 << (m-1-j);
        int set = 0;

        for(int i=0; i<n; i++){
            if(grid[i][j] == grid[i][0]){
                set++;
            }
        }

        ans += max(set, n-set)*val;
       } 

       return ans;
    }
};