class Solution {
public:
    string reverseWords(string s) {
        // 01.10.23 POTD
        stack<string> st;
        string t;

        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' '){
                st.push(t);
                t="";
            }
            else{
                t += s[i];
            }
        }

        while(st.size()){
            t += " " + st.top();

            st.pop();
        }

        return t;
    }
};