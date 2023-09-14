class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 14.09.23

        
        sort(intervals.begin(), intervals.end());

        int remCnt = 1, n=intervals.size();
        pair<int,int> prev = {intervals[0][0], intervals[0][1]};

        for(int i=1; i<n; i++){
            if(intervals[i][1] > prev.second){
                if(prev.first == intervals[i][0]){
                    prev.second = intervals[i][1];
                }
                else{
                    prev = {intervals[i][0], intervals[i][1]};
                    remCnt++;
                }
            }
        }

        return remCnt;
    }
};