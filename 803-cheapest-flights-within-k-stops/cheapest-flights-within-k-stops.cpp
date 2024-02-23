class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 23.02.24 potd
        unordered_map<int, vector<pair<int,int>>> adj;
        vector<int> vis(n, INT_MAX);
        vis[src]=0;

        for(const auto &x: flights){
            adj[x[0]].push_back({x[1],x[2]});
        }

        int count=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        k++;

        while(k--){
            int size=q.size();
            while(size--){
                int curr_price=q.front().second;
                for(auto &x: adj[q.front().first]){
                    int new_price=x.second+curr_price;
                    if(new_price < vis[x.first]){
                        vis[x.first]=new_price;
                        q.push({x.first,new_price});
                    }
                }
                q.pop();
            }
            count++;
        }

        return (vis[dst]==INT_MAX)? -1:vis[dst];
    }
};