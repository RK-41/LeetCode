class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // 17.02.24 potd
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> hDiff;

        for(int i=0; i<heights.size()-1; i++){
            int diff = heights[i+1]-heights[i];

            if(diff > 0){
                hDiff.push(diff);

                if(hDiff.size() > ladders){
                    int minReq = hDiff.top(); // min bricks req.t or min hDiff yet
                    hDiff.pop();
                    bricks -= minReq;

                    if(bricks < 0){
                        return i;
                    }
                }
            }
        }

        return heights.size()-1;
    }
};