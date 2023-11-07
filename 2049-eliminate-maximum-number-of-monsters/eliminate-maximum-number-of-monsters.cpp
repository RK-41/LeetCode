class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // 07.11.23 potd

        // Approach 1: Greedy Initial & Counting Sort
        int n = dist.size();
        vector<double> eta(n);

        for(int i=0; i<n; i++){
            eta[i] = static_cast<double>(dist[i])/speed[i];
        }

        sort(eta.begin(), eta.end());

        for(int i=0; i<n; i++){
            if(eta[i] <= i)
                return i;
        }

        return n;


        // APPROACH 2:
        // int ans = 0, minutes = 0;

        // for(int i=0; i<dist.size(); i++){
        //     if(dist[i] <= minutes*speed[i])
        //         break;

        //     minutes++;
        //     ans++;
        // }

        // return ans;
    }
};