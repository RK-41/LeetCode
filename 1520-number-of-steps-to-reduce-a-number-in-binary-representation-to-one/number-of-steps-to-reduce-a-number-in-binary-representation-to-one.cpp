class Solution {
public:
    int numSteps(string s) {
        // 29.05.24 POTD
        int ans=0;

        while(s.size()>1){
            int n=s.size();
            if(s[n-1] == '0'){
                s = s.substr(0,n-1);
            } else {
                char carry='0';
                for(int i=n-1; i>=0; i--){
                    if(s[i] == '0'){
                        s[i] = '1';
                        carry='0';
                        break;
                    } else {
                        s[i] = '0';
                        carry = '1';
                    }
                }

                if(carry == '1'){
                    s = '1' + s;
                }
            }

            ans++;
        }

        return ans;
    }
};