class Solution {
public:
    string frequencySort(string s) {
        // 07.02.24 
        unordered_map<char,int> fr;
        for(auto c: s){
            fr[c]++;
        }

        priority_queue<pair<int,char>> p;
        for(auto f: fr){
            p.push({f.second,f.first});
        }

        s="";
        while(p.size()){
            int l=p.top().first;
            char c=p.top().second;
            while(l--){
                s += c;
            }
            p.pop();
        }
    
        return s;
    }
};