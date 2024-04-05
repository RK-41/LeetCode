class Solution {
public:
    string makeGood(string s) {
        // 05.04.24 potd
        if(s.size()==1)
            return s;

        string ans;
        stack<char> stk;

        for(char c: s){
            if(!stk.empty() && abs(c - stk.top()) == 32){
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};