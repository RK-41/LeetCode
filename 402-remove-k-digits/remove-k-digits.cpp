class Solution {
public:
    string removeKdigits(string num, int k) {
        // 11.04.24 potd
        if(num.size()==k)
            return "0";

        string ans;
        stack<char> stk;

        for(char d: num){
            while(stk.size() && k>0 && stk.top()>d){
                stk.pop();
                k--;
            }
            stk.push(d);
        }

        // Remove remaining k digits from the end of the stack
        while(k>0 && stk.size()){
            stk.pop();
            k--;
        }

        // Construct the resulting string from the stack
        while(stk.size()){
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        size_t pos = ans.find_first_not_of('0');
        ans = (pos == string::npos) ? "0" : ans.substr(pos);

        return ans;
    }
};