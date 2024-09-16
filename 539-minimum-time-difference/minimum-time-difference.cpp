class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // 16.09.24 potd
        int ans=INT_MAX;
        vector<int> mins;

        for(auto tp: timePoints){
            int hr = stoi(tp.substr(0,2));
            int min = stoi(tp.substr(3,2));
            mins.push_back(hr*60 + min);
        }

        sort(mins.begin(), mins.end());
        for(int i=1; i<mins.size(); i++){
            ans = min(ans, mins[i]-mins[i-1]);
        }

        ans = min(ans, 1440 - mins.back() + mins.front());
        
        return ans;
    }
};