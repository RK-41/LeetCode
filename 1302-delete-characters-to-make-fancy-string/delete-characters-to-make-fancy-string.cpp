class Solution {
public:
    string makeFancyString(string s) {
        // 01.11.24 POTD
        string ans;
        int count=1;

        for(auto c: s){
            if(!ans.empty() && c == ans.back())
                count++;
            else
                count = 1;

            if(count<3)
                ans += c;
        }

        return ans;
    }
};