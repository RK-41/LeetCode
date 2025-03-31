class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // 31.03.25 potd
        if(k == 1)
            return 0;

        vector<int> pairSums;

        for(size_t i=0; i<weights.size() - 1; i++){
            pairSums.push_back(weights[i] + weights[i+1]);
        }

        sort(pairSums.begin(), pairSums.end());

        long long minScore = accumulate(pairSums.begin(), pairSums.begin() + (k - 1), 0LL);
        long long maxScore = accumulate(pairSums.end() - (k - 1), pairSums.end(), 0LL);

        return maxScore - minScore;
    }
};