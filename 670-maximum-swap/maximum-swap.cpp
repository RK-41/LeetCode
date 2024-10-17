class Solution {
public:
    int maximumSwap(int num) {
        // 17.10.24 potd
        vector<int> lastIdx(10, -1);
        string strNum = to_string(num);
        int n = strNum.size();

        for(int i=0; i<n; i++){
            lastIdx[strNum[i] - '0'] = i;
        }

        for(int i=0; i<n; i++){
            for(int d=9; d>strNum[i]-'0'; --d){
                if(lastIdx[d]>i){
                    swap(strNum[i], strNum[lastIdx[d]]);
                    return stoi(strNum);
                }
            }
        }

        return num;
    }
};