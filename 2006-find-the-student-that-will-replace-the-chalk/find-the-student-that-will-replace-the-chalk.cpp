class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // 02.09.24 pOTD
        int ans=0, n=chalk.size();
        long long int count = 0;

        for(int i=0; i<n; i++){
            count += chalk[i];
        }

        k %= count;
        while(chalk[ans] <= k){
            k -= chalk[ans++];
        }

        return ans;
    }
};