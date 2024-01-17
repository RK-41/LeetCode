class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // 17.01.24 POTD
        unordered_map<int,int> fr, frfr;

        for(auto a: arr){
            fr[a]++;
        }

        for(auto p: fr){
            if(frfr.find(p.second)!=frfr.end())
                return false;

            frfr[p.second]++;
        }

        return true;
    }
};