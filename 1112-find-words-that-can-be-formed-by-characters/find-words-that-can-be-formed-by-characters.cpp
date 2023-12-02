class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // 02.12.23 POTD

        int ans=0;
        unordered_map<char,int> ch;

        for(auto c: chars){
            ch[c]++;
        }

        for(auto w: words){
            int flg=1;
            unordered_map<char,int> temp;
            for(auto c: w){
                temp[c]++;
                if(temp[c] > ch[c] || ch[c] == 0){
                    flg=0;
                    cout<<w<<" "<<c<<" break; ";
                    break;
                }
            }
            
            if(flg==0)
                continue;

            // for(auto c: w){
            //     ch[c]--;
            // }

            ans += w.size();
        }

        return ans;
    }
};