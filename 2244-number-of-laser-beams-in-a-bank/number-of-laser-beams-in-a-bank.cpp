class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0, curr=0, prev=0;

        for(int i=0; i<bank.size(); i++){
            for(int j=0; j<bank[i].size(); j++){
                curr += (bank[i][j]-'0');
            }

            if(prev>0 and curr>0){
                ans += prev*curr;
                prev = curr;
                curr = 0;
            } else if(prev==0){
                prev = curr;
                curr = 0;
            }
        }

        return ans;
    }
};