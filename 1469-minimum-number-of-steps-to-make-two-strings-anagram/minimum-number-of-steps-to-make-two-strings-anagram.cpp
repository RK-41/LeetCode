class Solution {
public:
    int minSteps(string s, string t) {
        // 13.01.24 POTD
        int ans=0;
        unordered_map<int,int> count;

        for(auto c: s){
            count[c]++;
        }

        for(auto c: t){
            count[c]--;
        }

        for(auto p: count){
            ans += abs(p.second);
        }

        return ans/2;
    }
};