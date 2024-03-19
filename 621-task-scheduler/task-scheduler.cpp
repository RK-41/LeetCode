#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 19.03.24 potd
        int maxFr=0, maxFrCount=0, sz=tasks.size();
        int fr[26]={0};

        for(char c: tasks){
            int f = ++fr[c-'A'];
            if(f == maxFr)
                maxFrCount++;
            else if(f > maxFr){
                maxFr = f;
                maxFrCount = 1;
            }
        }

        int time = (maxFr-1)*(n+1)+maxFrCount;
        return max(time, sz); 
    }
};