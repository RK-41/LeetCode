class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // 31.12.23 POTD
        int ans=0;
        unordered_map<char,int> count, first, last;
        for(int i=0; i<s.size(); i++){
            count[s[i]]++;
            if(count[s[i]]==1){
                first[s[i]]=i;
            } else {
                // last[s[i]]=i;
                ans = max(ans, i - first[s[i]] - 1);
            }
        }

        if(count.size()==s.size())
            return -1;

        // for(auto p: first){
            // ans = max(ans, last[p.first]-p.second-1);
        // }

        return ans;
    }
};