class Solution {
public:
    int minimumPushes(string word) {
        // 06.08.24 POTD
        int ans=0, n=word.size();
        unordered_map<char,int> fr, um;
        vector<pair<int,char>> v;

        // Finding frequency of each char in 'word'
        for(auto w: word){
            fr[w]++;
        }

        // Creating a vector of pair{fr,char} for each unique char in 'word'
        for(auto f: fr){
            v.push_back({f.second,f.first});
        }

        sort(v.rbegin(), v.rend());
        int idx = 0, vs = v.size();

        for(int i=1; idx<vs; i++){  // No. of pushes
            for(int j=2; j<=9; j++){    // Traversing buttons from 2 to 9
                if(idx == vs)
                    break;

                um[v[idx++].second] = i;
            }
        }

        // Traversing 'word' for final calculation
        for(auto w: word){
            ans += um[w];
        }

        return ans;
    }
};