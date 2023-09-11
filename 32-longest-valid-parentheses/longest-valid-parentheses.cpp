class Solution {
public:
    int longestValidParentheses(string s) {
        // 11.09.23
        if(s.size()==1)     return 0;

        vector<int> valid(s.size(), 0);
        stack<pair<char,int>> stk;
        int ans=0;

        for(int i=0; i<s.size(); i++){
            if(isOpen(s[i])){
                stk.push({s[i],i});
            }

            else if(stk.empty()){
                continue;
            }

            else{
                if(match(stk.top().first, s[i])){
                    valid[i] = 1;
                    valid[stk.top().second] = 1;

                    stk.pop();
                }
            }
        }

        int cnt=0;
        for(auto i: valid){
            if(i==0){
                ans = max(ans, cnt);
                cnt = 0;
            }    
                
            else
                cnt++;
        }

        return max(ans, cnt);
    }

    bool isOpen(char p){
        return p=='(' || p=='{' || p=='[';
    }

    bool match(char a, char b){
        return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
    }
};