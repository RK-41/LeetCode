class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // 20.07.24 potd(Algo)
        int n = rowSum.size(), m = colSum.size(), i = 0, j = 0;
        vector<vector<int>> mat(n, vector<int>(m, 0));

        while(i!=n && j!=m){
            if(i == n){
                mat[i-1][j] = colSum[j];
            }

            if(j == m){
                mat[i][j-1] = rowSum[i];
            }

            int d = min(rowSum[i], colSum[j]);
            rowSum[i] -= d;
            colSum[j] -= d;

            mat[i][j] = d;

            if(rowSum[i] == 0){
                i++;
            }

            if(colSum[j] == 0){
                j++;
            }
        }

        return mat;
    }
};