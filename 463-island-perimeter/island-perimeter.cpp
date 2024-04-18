class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // 18.04.24 POTD
        int ans=0, r=grid.size(), c=grid[0].size();

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 0)
                    continue;

                if(i==0)    ans++;
                if(i==r-1)  ans++;
                if(j==0)    ans++;
                if(j==c-1)  ans++;
                if(i>0 && grid[i-1][j]==0)  ans++;
                if(i<r-1 && grid[i+1][j]==0)    ans++;
                if(j>0 && grid[i][j-1]==0)  ans++;
                if(j<c-1 && grid[i][j+1]==0)    ans++;
            }
        }

        return ans;
    }
};