class Solution {
public:
    string largestOddNumber(string num) {
        // 07.12.23 POTD

        int i=num.size()-1;

        while(i>=0){
            int d = num[i]-'0';
            if(d%2==1)
                break;

            i--;
        }

        return num.substr(0,i+1);
    }
};