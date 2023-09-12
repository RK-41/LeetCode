class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        unordered_map<int,int> charFr;
        map<int,int> frFr;

        for(auto ch: s){
            charFr[ch]++;
        }

        for(auto cf: charFr){
            frFr[cf.second]++;
        }

        for(auto ff=frFr.rbegin(); ff!=frFr.rend(); ff++){
            while(ff->second > 1){
                ans++;
                ff->second--;

                if(ff->first > 1)   
                    frFr[ff->first-1]++;
                    
                cout<<ff->first<<" "<<ff->second<<endl;
            }
        }

        return ans;
    }
};