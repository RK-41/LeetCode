class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // 10.12.23 POTD

        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> trans;

        for(int j=0; j<m; j++){
            vector<int> v;
            for(int i=0; i<n; i++){
                v.push_back(matrix[i][j]);
            }

            trans.push_back(v);
        }

        return trans;
    }
};