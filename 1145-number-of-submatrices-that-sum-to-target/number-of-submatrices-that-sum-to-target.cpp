class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // 28.01.24 potd
        int m=matrix.size(), n=matrix[0].size(), ans=0;

        for(int l=0; l<n; l++){
            int sums[105] = {0};
            for(int r=l; r<n; ++r){
                for(int i=0; i<m; ++i){
                    sums[i] += matrix[i][r];
                }

                for(int i=0; i<m; ++i){
                    int sum=0;
                    for(int j=i; j<m; ++j){
                        sum += sums[j];
                        if(sum==target){
                            ++ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};