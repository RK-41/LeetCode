class Solution {
public:
    string numberToWords(int num) {
        // 07.08.24 potd
        if(num == 0)    return "Zero";

        string bigStr[] = {"Thousand", "Million", "Billion"};
        string ans = helper(num%1000);
        num /= 1000;

        for(int i=0; i<3; i++){
            if(num > 0 && num % 1000 > 0){
                ans = helper(num%1000) + bigStr[i] + " " + ans;
            }

            num /= 1000;
        }

        return ans.empty() ? ans : ans.substr(0, ans.size() - 1);
    }

    string helper(int num){
        string digStr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teenStr[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tenStr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string res = "";
        if(num > 99){
            res += digStr[num/100] + " Hundred ";
        }
        num %= 100;

        if(num < 20 && num > 9){
            res += teenStr[num-10] + " ";
        } else {
            if(num >= 20){
                res += tenStr[num/10] + " ";
            }
            num %= 10;

            if(num > 0){
                res += digStr[num] + " ";
            }
        }

        return res;
    }
};