class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // 20.01.25 POTD
        int m = mat.size(), n = mat[0].size(), arrLen = arr.size();
        unordered_map<int,vector<pair<int,int>>> um;
        vector<set<int>> row(m), col(n);

        // Storing occurrence position of each number
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                um[mat[i][j]].push_back({i,j});
            }
        }

        for(int i=0; i<arrLen; i++){
            vector<pair<int,int>> v = um[arr[i]];
            for(auto pr: v){
                int r = pr.first;
                int c = pr.second;

                // Inserting col c in row r
                row[r].insert(c);

                // Inserting row r in col c
                col[c].insert(r);

                // Checking if row r or col c is filled
                if(row[r].size() == n || col[c].size() == m)
                    return i;
            }
        }

        return -1;
    }
};