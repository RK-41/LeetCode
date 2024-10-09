class Solution {
public:
    int minAddToMakeValid(string s) {
        // 09.10.24 potd
        int op=0, cl=0;

        for(auto c: s){
            if(c=='('){
                op++;
            } else {
                if(op>0)    op--;
                else        cl++;
            }
        }

        return op+cl;
    }
};