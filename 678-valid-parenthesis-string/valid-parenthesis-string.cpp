class Solution {
public:
    bool checkValidString(string s) {
        // 07.04.24 POtd
        int left=0, right=0, ast=0, cnt=0;

        for(char c: s){
            if(c=='('){
                left++;
                cnt++;
            }  
            else if(c==')'){
                right++;
                cnt--;
            }
            else{
                ast++;
                cnt--;
            }

            if(right > left+ast)
                return false;

            cnt = max(cnt, 0);
        }

        return cnt==0;
    }
};