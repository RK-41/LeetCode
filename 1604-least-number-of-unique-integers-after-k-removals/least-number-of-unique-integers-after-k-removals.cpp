class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // 16.02.24 POTD
        if(k == arr.size())
            return 0;

        unordered_map<int,int> fr;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto a: arr){
            fr[a]++;
        }

        for(auto p: fr){
            pq.push({p.second, p.first});
        }

        while(k>0){
            k -= pq.top().first;
            
            if(k>=0)
                pq.pop();
        }

        return pq.size();
    }
};