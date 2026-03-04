class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // 13.12.23 potd

        int specials=0;
        for(int i=0; i<mat.size(); i++){
            int idx = checkRow(mat, i);
            if(idx >= 0 && checkColumn(mat, i, idx))
                specials++;
        }

        return specials;
    }

    int checkRow(vector<vector<int>> &mat, int i){
        int idx = -1;
        for(int j=0; j<mat[0].size(); j++){
            if(mat[i][j] == 1){
                if(idx >= 0)
                    return -1;
                else
                    idx = j;
            }
        }

        return idx;
    }

    bool checkColumn(vector<vector<int>> &mat, int i, int idx){
        for(int j=0; j<mat.size(); j++){
            if(mat[j][idx] == 1 && j != i){
                return false;
            }
        }

        return true;
    }
};