class Solution {
public:
    char findTheDifference(string s, string t) {
        // 25.09.23 POTD

        unordered_map<char,int> fr;
        char ans='0';

        for(int i=0; i<s.size(); i++){
            fr[s[i]]--;
            fr[t[i]]++;
        }

        fr[t.back()]++;

        for(auto it: fr){
            if(it.second==1){
                ans=it.first;
                break;
            }
        }

        return ans=='0'? t.back(): ans;;
    }
};
