class Solution {
public:
    int minDeletions(string s) {
        // 12.09.23 POTD
        // Greedy Approach (vanAmsen's)

        int ans=0;
        unordered_map<int,int> charFr;
        map<int,int> frFr;
        // ans: stores deletion count
        // charFr: stores char frequencies
        // frFr: stores frequency of individual char frequencies

        for(auto ch: s){
            charFr[ch]++;
        }

        for(auto cf: charFr){
            frFr[cf.second]++;
        }

        // interating map frFr from end (in descending order of frequency)
        for(auto ff=frFr.rbegin(); ff!=frFr.rend(); ff++){
            // if fr of curr char-fr is greater than 1, it means two char have same frequency
            // this needs to be reduced
            while(ff->second > 1){
                // decrementing fr of curr char-fr means deleting an instance of curr char
                ff->second--;
                ans++;

                // since, ff->second has been decremented, the fr of char-fr of size 'ff->first' gets incremenetd
                // so, if curr char-fr (ff->first) is greater than 1, fr for 'curr-char-fr'-1 has to be incremented as ff->second has been decremented
                if(ff->first > 1)   
                    frFr[ff->first-1]++;
            }
        }

        return ans;
    }
};