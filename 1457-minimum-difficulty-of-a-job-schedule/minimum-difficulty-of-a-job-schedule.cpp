class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // 29.12.23 potd
        // Approach: Memoization
        int len=jobDifficulty.size();
        if(len<d)   return -1;

        int sum=accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        if(sum==0)  return 0;

        vector<vector<int>> memo(d+1, vector<int>(len,0));
        memoize(jobDifficulty, d, 0, memo);
        
        return memo[d][0];
    }
private:
    void memoize(vector<int>&jd, int daysLeft, int idx, vector<vector<int>>&memo){
        if(memo[daysLeft][idx]!=0)  return;

        int len=jd.size();
        if(daysLeft==1){
            int num=0;
            for(int i=idx; i<len; i++){
                num=max(num, jd[i]);
            }
            memo[daysLeft][idx]=num;
            return;
        }

        int maxDifficulty=jd[idx];
        daysLeft--;
        int stop=len-idx-daysLeft+1;
        int res=INT_MAX;
        for(int i=1; i<stop; i++){
            maxDifficulty=max(maxDifficulty, jd[idx+i-1]);
            int other=memo[daysLeft][idx+i];
            if(other==0){
                memoize(jd, daysLeft, idx+i, memo);
                other=memo[daysLeft][idx+i];
            }
            res=min(res, other+maxDifficulty);
        }

        memo[daysLeft+1][idx]=res;
    }
};