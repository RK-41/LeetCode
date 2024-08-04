class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // 04.08.24 Potd
        unordered_map<int,int> fr;

        for(auto t: target){
            fr[t]++;
        }

        for(auto a: arr){
            fr[a]--;

            if(fr[a] == 0)
                fr.erase(a);
        }

        return !fr.size();
    }
};