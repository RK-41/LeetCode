class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        // 20.06.24 potd
        sort(pos.begin(), pos.end());

        int ans=1;
        int lo=1, hi=(pos.back()-pos[0])/(m-1);

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(ballCanBePlaced(pos, mid, m)){
                ans = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        return ans;
    }

private:
    bool ballCanBePlaced(const vector<int>&pos, int dist, int balls){
        int countBalls = 1, lastPlaced = pos[0];

        for(int i=1; i<pos.size(); i++){
            if(pos[i] - lastPlaced >= dist){
                countBalls++;
                lastPlaced = pos[i];
            }
            if(countBalls >= balls){
                return true;
            }
        }

        return false;
    }
};