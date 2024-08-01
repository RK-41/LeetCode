class Solution {
public:
    int countSeniors(vector<string>& details) {
        // 01.08.24 POTD
        int ans=0;
        for(auto d: details){
            if((d[11] == '6' && d[12] > '0') || (d[11] > '6')){
                ans++;
            }
        }

        return ans;
    }
};