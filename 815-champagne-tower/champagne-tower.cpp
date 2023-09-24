class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // 24.09.23
        // Approach: DP

        // Creating a vector representing the current row of glasses
        vector<double> currRow(1, poured);

        // Loop through each row up to the query_row
        for(int i=0; i<=query_row; i++){

            // Creating a vector to represent the next row of glasses
            vector<double> nextRow(i+2,0);

            // Loop through each glass in the current row
            for(int j=0; j<=i; j++){

                // If the current glass has champagne overflowing (more than 1 unit),
                //  distribute the excess champagne equally to the two glasses in the
                //  next row below
                if(currRow[j] >= 1){
                    nextRow[j] += (currRow[j] - 1)/2.0;
                    nextRow[j+1] += (currRow[j] - 1)/2.0;

                    // Set the current glass to have exactly 1 unit of champagne
                    currRow[j] = 1;
                }
            }

            // If query_row haven't been reached, update the current row to the next row
            if(i != query_row)  currRow = nextRow;
        }

        // The champagne in the specified glass in the query_row in the result
        return currRow[query_glass];
    }
};