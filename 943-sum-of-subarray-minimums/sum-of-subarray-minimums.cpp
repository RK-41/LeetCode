class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // 20.01.24 potd
        const int MOD = 1000000007;
        stack<int> stk;
        long sum = 0;

        for(int i=0; i<=arr.size(); i++){
            while(!stk.empty() && (i==arr.size() || arr[stk.top()]>=arr[i])){
                int mid = stk.top();
                stk.pop();
                int lBoundry = stk.empty()? -1 : stk.top();
                int rBoundry = i;

                long count = (mid - lBoundry) * (rBoundry - mid) % MOD;

                sum += (count*arr[mid])%MOD;
                sum %= MOD;
            }

            stk
            .push(i);
        }

        return static_cast<int>(sum);
    }
};