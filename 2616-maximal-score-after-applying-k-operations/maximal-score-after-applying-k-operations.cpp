class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // 14.10.24 POTD
        long long ans=0;
        priority_queue<int> pq = {nums.begin(), nums.end()};

        while(k--){
            ans += pq.top();
            int t = pq.top();
            pq.pop();
            pq.push(ceil((double)t/3));
        }

        return ans;
    }
};