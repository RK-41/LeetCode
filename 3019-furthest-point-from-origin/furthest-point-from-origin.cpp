class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // 24.04.26 POTD
        int ans = 0, blank = 0;

        for(char m: moves){
            if(m == 'R')    ans++;
            else if(m == 'L')   ans--;
            else    blank++;
        }

        if(ans<0)   ans = abs(ans);
        
        ans += blank;

        return ans;
    }
};