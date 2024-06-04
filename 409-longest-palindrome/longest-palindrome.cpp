class Solution {
public:
    int longestPalindrome(string s) {
        // 04.06.24 POTD
        int ans=0, n=s.size();
        bool oddFound = false;
        unordered_map<char,int> fr;
        
        for(char c: s){
            fr[c]++;
        }

        for(auto f: fr){
            if(f.second%2){
                oddFound = true;
                ans += f.second-1;
            } else {
                ans += f.second;
            }
        }

        if(oddFound){
            ans++;
        }

        return ans;
    }
};