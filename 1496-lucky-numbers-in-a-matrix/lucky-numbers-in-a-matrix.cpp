class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // 19.07.24 POTD
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans, rowMin(m, INT_MAX), colMax(n);
        int mn = matrix[0][0], mx = matrix[0][0];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }

        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
                    ans.push_back(matrix[i][j]);
            }
        }

        return ans;
    }
};