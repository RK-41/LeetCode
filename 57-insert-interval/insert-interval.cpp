class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 17.03.24 POTD
        vector<vector<int>> ans;
        int istart=newInterval[0], iend=newInterval[1], an=0;

        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        
        if(iend < intervals[0][0]){
            ans.push_back({istart,iend});
        }

        for(int i=0; i<intervals.size(); i++){
            if(iend < intervals[i][0] && (an>0 && istart>ans[an-1][1])){
                ans.push_back({istart, iend});
                an++;
                i--;
            } else if(istart<=intervals[i][1] && iend>=intervals[i][0]) {
                istart=min(istart,intervals[i][0]);
                iend=max(iend,intervals[i][1]);

                if(an>0 && (istart==ans[an-1][0] && iend>=ans[an-1][1])){
                    ans[an-1][1]=iend;
                } else {
                    ans.push_back({istart,iend});
                    an++;
                }
            } else if(istart>intervals[i][1] || iend<intervals[i][0]){
                ans.push_back(intervals[i]);
                an++;
            } 
        }
        
        if(ans[an-1][1] < istart){
            ans.push_back({istart,iend});
        }

        return ans;
    }
};