class Solution {
public:
    string reverseParentheses(string s) {
        // 11.07.24 POTD
        stack<int> open;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                open.push(i);
                cout<<i;
            }
            else if(s[i] == ')'){
                int start = open.top()+1, end = i-1;
                open.pop();

                if(start > end){
                    s = s.substr(0,end) + s.substr(end+2);
                } else {
                    string sub = s.substr(start, end-start+1);
                    reverse(sub.begin(), sub.end());

                    s = s.substr(0,start-1) + sub + s.substr(end+2);
                }

                i -= 2;
            }
        }

        return s;
    }
};