// 119. Pascal's Triangle II
class Solution {
public:
    vector<int> getRow(int rowIdx) {
        // 15.10.23 POTD

        vector<int> row{1};

        for(int i=1; i<=rowIdx; i++){
            vector<int> newRow(i+1,1);

            for(int j=1; j<i; j++)
                newRow[j] = row[j-1]+row[j];

            row = newRow;
        }

        return row;
    }
};