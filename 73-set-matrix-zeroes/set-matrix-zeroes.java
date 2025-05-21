class Solution {
    public void setZeroes(int[][] mat) {
        // 21.05.25 potd
        boolean zeroinFirstCol = false;
        for(int r=0; r<mat.length; r++){
            if(mat[r][0] == 0)  zeroinFirstCol = true;
            for(int c=1; c<mat[0].length; c++){
                if(mat[r][c] == 0){
                    mat[r][0] = 0;
                    mat[0][c] = 0;
                }
            }
        }

        for(int r=mat.length-1; r>=0; r--){
            for(int c=mat[0].length-1; c>=1; c--){
                if(mat[r][0] == 0 || mat[0][c] == 0){
                    mat[r][c] = 0;
                }
            }

            if(zeroinFirstCol){
                mat[r][0] = 0;
            }
        }
    }
}