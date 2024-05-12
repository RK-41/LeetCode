class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // 12.05.24 POTD

        int n=grid.size();
        vector<vector<int>> ans;

        for(int i=0; i<n-2; i++){
            vector<int> v;
            for(int j=0; j<n-2; j++){
                int a = *max_element(grid[i].begin()+j, grid[i].begin()+j+3);
                int b = *max_element(grid[i+1].begin()+j, grid[i+1].begin()+j+3);
                int c = *max_element(grid[i+2].begin()+j, grid[i+2].begin()+j+3);

                v.push_back(max(a,max(b,c)));
            }

            ans.push_back(v);
        }

        return ans;
    }
};