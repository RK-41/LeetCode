class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // 22.02.24 POTD
        unordered_map<int,int> trusted;
        for(auto t: trust){
            trusted[t[1]]++;    // Count of trust gained
            trusted[t[0]]--;    // t[0] can't be judge, so it can't have max trust count in any case
        }

        for(int i=1; i<=n; i++){
            // Trust count == n-1 -> Judge
            if(trusted[i] == n-1)
                return i;

        }

        return -1;
    }
};