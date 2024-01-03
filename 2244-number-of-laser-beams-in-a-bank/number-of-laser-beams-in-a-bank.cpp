class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // 03.01.24 POTD
        int ans=0, curr=0, prev=0;

        for(int i=0; i<bank.size(); i++){
            for(int j=0; j<bank[i].size(); j++){
                // curr += (bank[i][j]-'0');
                curr = accumulate(bank[i].begin(), bank[i].end(), -1*('0'*bank[i].size()));
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