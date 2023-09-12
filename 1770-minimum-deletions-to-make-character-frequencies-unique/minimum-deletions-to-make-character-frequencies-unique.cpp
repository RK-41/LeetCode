class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        unordered_map<int,int> charFr;
        map<int,int> frFr;
        priority_queue<pair<int,int>> q;

        for(auto ch: s){
            charFr[ch]++;
        }


        // for(auto &cf: charFr){
        //     while(cf.)
        // }


        for(auto cf: charFr){
            frFr[cf.second]++;
        }

        // for(auto &ff: frFr){

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
        // if(charFr.size()==1)
        //     return 0;

        // if(frFr.size()==1){
        //     auto key = *frFr.begin();
        //     if(key.second==2)
        //         return 1;
        //     if(key.first>1 && key.second>2)
        //         return key.second;
        // }

        // for(auto &ff: frFr){
        //     while(ff.second>1){
        //         int cnt = 0, curr = ff.first;

        //         while(frFr.find(curr)!= frFr.end() && curr>0){
        //             curr--;
        //             cnt++;
        //         }
        //         ff.second--;
        //         ans += cnt;
        //     }
        // }

        return ans;
    }
};