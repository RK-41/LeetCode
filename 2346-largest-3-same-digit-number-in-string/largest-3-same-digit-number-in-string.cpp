class Solution {
public:
    string largestGoodInteger(string num) {
        // 24.08.25 (POTD)

        string ans;
        int good=INT_MIN, len=1, prev;
        for(int i=1; i<num.size(); i++){
            if(num[i] == num[i-1]){
                len++;
            } else {
                len=1;
            }

            if(len==3){
                int nm = num[i]-'0';
                if(good != INT_MIN && nm <= prev)
                    continue;
                    
                prev = nm;

                nm = nm*10 + nm;
                nm = nm*10 + nm%10;

                good = nm;
                len=1;
            }
        }

        if(good==INT_MIN) return "";

        ans = to_string(good);
        if(ans == "0"){
            ans += "00";
        }

        return ans;
    }
};