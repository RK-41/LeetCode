class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // 18.11.24 POTD
        int n = code.size();
        vector<int> ans(n), cumSum = code;

        if(k==0) return ans;

        for(int i=1; i<n; i++){
            cumSum[i] += cumSum[i-1];
        }

        if(k > 0){
            for(int i=0; i<n; i++){
                int r = min(n-1, i+k);
                ans[i] += cumSum[r] - cumSum[i];

                if(r < i+k){
                    ans[i] += cumSum[i+k-r-1];
                }
            }
        } else {
            for(int i=0; i<n; i++){
                if(i > 0){
                    ans[i] += cumSum[i-1];
                }

                if(i+k > 0){
                    ans[i] -= cumSum[i+k-1];
                } else if(i+k < 0){
                    ans[i] += cumSum[n-1] - cumSum[n-1+i+k];
                }
            }
        }

        return ans;
    }
};