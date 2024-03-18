class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 18.03.24 POTD
        int ans=1;

        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int x1=points[0][0], x2=points[0][1];

        for(int i=1; i<points.size(); i++){
            if(x2>=points[i][0])
                continue;
            else {
                x2 = points[i][1];
                ans++;
            }
        }

        return ans;
    }
};