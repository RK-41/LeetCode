class Solution {
public:
    string minWindow(string s, string t) {
        // 04.02.24 potd
        if(s.empty() || t.empty() || s.length()<t.length())
            return "";

        vector<int> map(128,0);
        int cnt=t.length();
        int start=0, end=0, minLen=INT_MAX, startIdx=0;

        for(char c:t){
            map[c]++;
        }

        while(end < s.length()){
            if(map[s[end++]]-- > 0){
                cnt--;
            }

            while(cnt==0){
                if(end - start < minLen){
                    startIdx = start;
                    minLen = end-start;
                }

                if(map[s[start++]]++ == 0){
                    cnt++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};