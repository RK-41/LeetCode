class Solution {
public:
    string fractionAddition(string exp) {
        // 23.08.24 potd
        int nmr = 0, dnr = 1;
        int i = 0, n = exp.size();

        while(i<n){
            int sign = 1;
            if(exp[i] == '+' || exp[i] == '-'){
                if(exp[i] == '-')
                    sign = -1;
                i++;
            }

            int num = 0;
            while(i<n && isdigit(exp[i])){
                num = num*10 + (exp[i] - '0');
                i++;
            }

            num *= sign;
            i++;

            int den = 0;
            while(i<n && isdigit(exp[i])){
                den = den*10 + (exp[i] - '0');
                i++;
            }

            nmr = nmr * den + num * dnr;
            dnr *= den;

            int gcdVal = gcd(abs(nmr), dnr);
            nmr /= gcdVal;
            dnr /= gcdVal;
        }

        return to_string(nmr) + "/" + to_string(dnr);
    }
};