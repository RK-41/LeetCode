class Solution {
public:
    bool checkValidString(string s) {
        // 07.04.24
        int left=0, right=0, ast=0, last=0;
        int cnt=0;
        for(char c: s){
            if(c=='('){
                left++;
                last=-1;
                cnt++;
            }  
            else if(c==')'){
                right++;
                last=1;
                cnt--;
            }
            else{
                ast++;
                last=0;
                cnt--;
                cout<<"*";
            }

            if(right > left+ast)
                return false;

            cnt = max(cnt, 0);
            cout<<cnt<<" ";
        }

        if(last==-1)
            return false;

        return cnt==0;
    }
};